package Problem_of_the_day;


import java.util.Arrays;

public class Min_Cost_to_Connect_All_Points {


    static int [][][] pointsChecked = new int[1000][2][2];
    static int loop =0;

    public static void main(String[] args) {
        int[][] points = {
                {0, 0},
                {2, 2},
                {3, 10},
                {5, 2},
                {7, 0}
        };
        System.out.println(minCostConnectPoints(points));
    }

    public static int minCostConnectPoints(int[][] points) {
        int totalCost = 0;
        int shortestPath;
        int currentDistance;
        for (int i = 0; i < points.length; i++){
            shortestPath = Integer.MAX_VALUE;
            for (int j = 0; j < points.length; j++){
                if (i != j && shouldBeChecked(points[i], points[j])){
                    currentDistance = ManhattanDistance(points[i], points[j]);
                    if (currentDistance > 0 && currentDistance < shortestPath){
                        shortestPath = currentDistance;
                    }
                }
            }
            if (shortestPath != Integer.MAX_VALUE )
                totalCost += shortestPath;
        }

        return totalCost;
    }

    private static boolean shouldBeChecked(int[] point, int[] point1) {
//        for (int i = 0; i < loop; i++){
//            if (pointsChecked[i][0][0] == point[0] && pointsChecked[i][0][1] == point[1]){
//                    if (pointsChecked[i][1][0] == point1[0] && pointsChecked[i][1][1] == point1[1]){
//                        return  false;
//                    }
//
//                } else if (pointsChecked[i][1][0] == point[0] && pointsChecked[i][1][1] == point[1]){
//                if (pointsChecked[i][0][0] == point1[0] && pointsChecked[i][0][1] == point1[1]){
//                    return  false;
//                }
//                }
//        }
        for (int i = 0; i < loop; i++) {
            if (Arrays.equals(pointsChecked[i][0], point) && Arrays.equals(pointsChecked[i][1], point1)) {
                return false;
            } else if (Arrays.equals(pointsChecked[i][1], point) && Arrays.equals(pointsChecked[i][0], point1)) {
                return false;
            }
        }
        pointsChecked[loop][0] = point;
        pointsChecked[loop][1] = point1;
        loop++;
        return true;
    }

    public static int ManhattanDistance(int[]point1, int[]point2) {

        return Math.abs(point1[0] - point2[0]) + Math.abs(point1[1] - point2[1]);
    }
}
