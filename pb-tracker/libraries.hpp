

//
//  libraries.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef libraries_h
#define libraries_h

// MARK: - Commons
#include <common/log.hpp>
#include <common/thread.hpp>

// MARK: - Network
#include <network/network.hpp>
#include <network/Endpoint.hpp>
#include <network/Discovery/Browser.hpp>
#include <network/Messages/network.pb.h>
#include <network/Socket/Socket.hpp>
#include <network/Socket/SocketDelegate.hpp>

// MARK: - PB Commons
#include <pb-common/common.hpp>
#include <pb-common/messages.hpp>
#include <pb-common/Structs/Body.hpp>
#include <pb-common/Structs/RawBody.hpp>
#include <pb-common/Structs/Skeleton.hpp>
#include <pb-common/Structs/Joint.hpp>

// MARK: - OpenNI2/NiTE2
#ifdef __APPLE__
#    include <ni2/OpenNI.h>
#else
#    include <openni2/OpenNI.h>
#endif

#include <nite2/NiTE.h>

#endif /* libraries_h */
