/*
 * FenwickTree3D.h
 *
 *  Created on: Jun 16, 2017
 *      Author: Wesley Leung
 */

#ifndef DATASTRUCTURES_MATH_FENWICKTREE3D_H_
#define DATASTRUCTURES_MATH_FENWICKTREE3D_H_

#include <bits/stdc++.h>

using namespace std;

/**
 * Memory usage:  O(nmp)
 *
 * @author Wesley Leung
 */
struct FenwickTree3D {
private:
    int sizeX;
    int sizeY;
    int sizeZ;

public:
    int ***array;

    FenwickTree3D(int sizeX, int sizeY, int sizeZ) {
        this->sizeX = sizeX;
        this->sizeY = sizeY;
        this->sizeZ = sizeZ;
        array = new int**[sizeX + 1];
        for (int i = 0; i <= sizeX; i++) {
            array[i] = new int*[sizeY];
            for (int j = 0; j <= sizeY; j++) {
                array[i][j] = new int[sizeZ];
            }
        }
    }

    /**
     * Range Sum Query
     * <p>
     * Time-Complexity:    O(log(nmp))
     *
     * @param  indX x index
     * @param  indY y index
     * @param  indZ z index
     * @return sum
     */
    int rsq(int indX, int indY, int indZ) {
        int sum = 0;
        for (int x = indX; x > 0; x -= (x & -x)) {
            for (int y = indY; y > 0; y -= (y & -y)) {
                for (int z = indZ; z > 0; z -= (z & -z)) {
                    sum += array[x][y][z];
                }
            }
        }
        return sum;
    }

    /**
     * Range Sum Query
     * <p>
     * Time-Complexity:    O(log(nmp))
     *
     * @param  x1 top index
     * @param  y1 left index
     * @param  z1 from index
     * @param  x2 bottom index
     * @param  y2 right index
     * @param  z2 back index
     * @return sum
     */
    int rsq(int x1, int y1, int z1, int x2, int y2, int z2) {
        return rsq(x2, y2, z2)
                - rsq(x1 - 1, y2, z2) - rsq(x2, y1 - 1, z2) - rsq(x2, y2, z1 - 1)
                + rsq(x1 - 1, y1 - 1, z2) + rsq(x1 - 1, y2, z1 - 1) + rsq(x2, y1 - 1, z1 - 1)
                - rsq(x1 - 1, y1 - 1, z1 - 1);
    }

    /**
     * Update the array at [indX][indY][indZ] and all the affected regions above ind.
     * ind is 1-indexed
     * <p>
     * Time-Complexity:    O(log(nmp))
     *
     * @param  indX   x index
     * @param  indY   y index
     * @param  indZ   z index
     * @param  value value
     */
    void update(int indX, int indY, int indZ, int value) {
        for (int x = indX; x <= sizeX; x += (x & -x)) {
            for (int y = indY; y <= sizeY; y += (y & -y)) {
                for (int z = indZ; z <= sizeZ; z += (z & -z)) {
                    array[x][y][z] += value;
                }
            }
        }
    }

    int getSizeX() {
        return sizeX;
    }

    int getSizeY() {
        return sizeY;
    }

    int getSizeZ() {
        return sizeZ;
    }
};

#endif /* DATASTRUCTURES_MATH_FENWICKTREE3D_H_ */