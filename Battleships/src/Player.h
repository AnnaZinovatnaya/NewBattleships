/*
 * Player.h
 *
 *  Created on: Nov 17, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include <cstdlib>
#include <vector>

class Player {
public:
	Player();
	~Player();

	void makeMove(int & x, int & y);
    std::vector<std::vector<int> > getField();

    void notifyOnInjured();
    void notifyOnSunk();
    int checkMove(int x, int y);
protected:
private:
    std::vector<std::vector<int> > field;
};

#endif /* SRC_PLAYER_H_ */
