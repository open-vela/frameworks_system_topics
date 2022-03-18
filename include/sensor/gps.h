/*
 * Copyright (C) 2020 Xiaomi Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TOPICS_INCLUDE_SENSOR_GPS_H
#define __TOPICS_INCLUDE_SENSOR_GPS_H

#include <uORB/uORB.h>

struct sensor_gps {
    uint64_t timestamp; /* Time since system start, Units is microseconds */

    /* This is the timestamp which comes from the gps module. It might be
     * unavailable right after cold start, indicated by a value of 0,
     * Units is microseconds
     */
    uint64_t time_utc;

    float latitude; /* Unit is degrees */
    float longitude; /* Unit is degrees */
    float altitude; /* Altitude above MSL(mean seal level), Unit is SI m */
    float altitude_ellipsoid; /* Altitude bove Ellipsoid, Unit is SI m */

    float eph; /* GPS horizontal position accuracy (metres) */
    float epv; /* GPS vertical position accuracy (metres) */

    float hdop; /* Horizontal dilution of precision */
    float pdop; /* Position dilution of precision */
    float vdop; /* Vertical dilution of precision */

    float ground_speed; /* GPS ground speed, Unit is m/s */

    /* Course over ground (NOT heading, but direction of movement),
     * Unit is Si degrees
     */

    float course;

    uint32_t satellites_used; /* Number of satellites used */
};

struct sensor_gps_satellite {
    uint64_t timestamp; /* Time since system start, Units is microseconds */
    uint32_t count; /* Total number of messages of satellites visible */
    uint32_t satellites; /* Total number of satellites in view */

    struct statellite {
        uint32_t svid; /* Space vehicle ID */

        /* Elevation (0: right on top of receiver, 90: on the horizon)
         * of satellite
         */

        uint32_t elevation;

        /* Direction of satellite, 0: 0 deg, 255: 360 deg. */

        uint32_t azimuth;

        /* dBHz, Signal to noise ratio of satellite C/N0, range 0..99,
         * zero when not tracking this satellite
         */

        uint32_t snr;
    } info[4];
};

/* register this as object request broker structure */

ORB_DECLARE(sensor_gps);
ORB_DECLARE(sensor_gps_satellite);

#endif
