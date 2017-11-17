/*
 * BattleshipsTypesHelper.h
 *
 *  Created on: Nov 17, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_BATTLESHIPSHELPER_H_
#define SRC_BATTLESHIPSHELPER_H_

namespace battleships {
   const int FIELD_SIZE = 10;

   enum playerState {
	   MISSED   = 0,
	   INJURED  = 1,
	   SUNK     = 2,
	   DEFEATED = 3
   };

   enum players {
	   PLAYER_1 = 1,
	   PLAYER_2 = 2
   };

   enum move {
	   MISS    = 0,
	   SUCCESS = 1,
   };
}

#endif /* SRC_BATTLESHIPSHELPER_H_ */
