//
//  Tracker.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef Tracker_h
#define Tracker_h

#include <functional>

namespace pb {

struct RawBody;

namespace tracker {

class Device;

/// A tracker takes an acquisition device and do Human Pose Estimation on the
/// device's stream
class Tracker {
public:
	/// This method is called everytime a body as been parsed by the tracker.
	/// It is the handler responsabiliy to free the memory used by the memory
	std::function<void(pb::RawBody *)> bodyHandler;

	virtual Device * getDevice() = 0;

	virtual ~Tracker() {};
};

} /* ::tracker */
} /* ::pb */

#include "NiteTracker.hpp"

#endif /* Tracker_h */
