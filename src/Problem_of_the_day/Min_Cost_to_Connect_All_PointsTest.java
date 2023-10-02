package Problem_of_the_day;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Min_Cost_to_Connect_All_PointsTest {

    @Test
    void minCostConnectPoints() {
        int[][] points = {
                {0, 0},
                {2, 2},
                {3, 10},
                {5, 2},
                {7, 0}
        };
        System.out.println(Min_Cost_to_Connect_All_Points.minCostConnectPoints(points));
    }
}