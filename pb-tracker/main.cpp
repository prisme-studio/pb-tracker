//
//  main.cpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-17.
//

#include <csignal>

#include <network/Engine.hpp>
#include <common/flags.hpp>

#include "libraries.hpp"
#include "Core/Core.hpp"

void signalHandler(int signum) {
	LOG_INFO("Closing...");

	// Properly terminate the application services
	pb::tracker::Core::instance()->terminate();

	exit(signum);
}

int main(int argc, const char * argv[]) {

	// Register our closing mechanisms
	signal(SIGINT, signalHandler);

	// Init the flags
	po::options_description desc("pb-master");
	flags::parse(argc, argv, desc);

	// Set the application type on the Network
	network::Engine::thisMachineType = "Tracker";

	// Init the app
	pb::tracker::Core::instance()->init();

	// Start the runLoop
	pb::tracker::Core::instance()->run();

	return 0;
}
