//
//  Core.cpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-20.
//

#include <boost/bind.hpp>
#include <pthread.h>

#include "Core.hpp"

namespace pb {
namespace tracker {

Core * Core::_instance = nullptr;

void Core::init() {
	// Name our main thread
	thread::setName("pb.tracker.main");

	// Setup the Pose estimation engine
	_poseEngine.onRawBodies = [&] (const std::set<pb::RawBody *, pb::RawBodyComparator> &rawBodies) {
		onRawBodies(rawBodies);
	};
	_poseEngine.start();

	_socket.delegate = this;

	// Start browsing
	_browser.onReceive = [&] (const ::network::Endpoint &endpoint) {
		_browser.stopBrowsing();
		_socket.connectTo(endpoint.ip, serverPortTracker);
	};

	_browser.startBrowsing(discoveryPortTracker);

	// Init our display
//	_interface.display();
}

void Core::run() {
	while(true) {
		std::string input;
		std::cin >> input;

		if(input == "q")
			return;
	}
}

void Core::terminate() {
	delete _instance;
}

void Core::onRawBodies(const std::set<pb::RawBody *, pb::RawBodyComparator> &rawBodies) {

	if(_socket.getStatus() != ::network::SocketStatus::ready)
		return;

	::network::messages::Datagram * datagram;

	for(pb::RawBody * rawBody: rawBodies) {
		datagram = makeDatagram(DatagramType::rawBody, (pb::messages::RawBody)*rawBody);

		_socket.send(datagram);

		datagram->Clear();
		delete datagram;
	}
}

Core::~Core() {}

void Core::socketDidOpen(::network::BaseSocket *) {
}

void Core::socketDidClose(::network::BaseSocket *) {
	_browser.startBrowsing(discoveryPortTracker);
}

} /* ::tracker */
} /* ::pb */
