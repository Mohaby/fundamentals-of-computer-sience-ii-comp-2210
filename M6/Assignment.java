import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;
   
public class ProgrammingHW_v2 {      
   // Algorithm-1
   public static int algorithm1(int[] X) {
      int maxSoFar = 0;
      for (int L = 0; L < X.length; L++) {
         for (int U = L; U < X.length; U++) {
            int sum = 0;
            for (int I = L; I <= U; I++) {
               sum += X[I];
            }
            maxSoFar = Math.max(maxSoFar, sum);
         }
      }
      return Math.max(maxSoFar, 0);
   }
   
   // Algorithm-2
   public static int algorithm2(int[] X) {
      int maxSoFar = 0;
      for (int L = 0; L < X.length; L++) {
         int sum = 0;
         for (int U = L; U < X.length; U++) {
            sum += X[U];
            maxSoFar = Math.max(maxSoFar, sum);
         }
      }
      return Math.max(maxSoFar, 0);
   }
   
   // Algorithm-3
   public static int maxSumCrossing(int[] X, int L, int M, int U) {
      int sum = 0;
      int maxToLeft = 0;
      for (int I = M; I >= L; I--) {
         sum += X[I];
         maxToLeft = Math.max(maxToLeft, sum);
      }
      
      sum = 0;
      int maxToRight = 0;
      for (int I = M + 1; I <= U; I++) {
         sum += X[I];
         maxToRight = Math.max(maxToRight, sum);
      }
      
      return maxToLeft + maxToRight;
   }
   
   public static int algorithm3(int[] X, int L, int U) {
      if (L > U) {
         return 0;
      }
      
      if (L == U) {
         return Math.max(0, X[L]);
      }
      
      int M = (L + U) / 2;
      int maxCrossing = maxSumCrossing(X, L, M, U);
      int maxInA = algorithm3(X, L, M);
      int maxInB = algorithm3(X, M + 1, U);
      
      return Math.max(maxCrossing, Math.max(maxInA, maxInB));
   }
   
   // Algorithm-4
   public static int algorithm4(int[] X) {
      int maxSoFar = 0;
      int maxEndingHere = 0;
      
      for (int I = 0; I < X.length; I++) {
         maxEndingHere = Math.max(0, maxEndingHere + X[I]);
         maxSoFar = Math.max(maxSoFar, maxEndingHere);
      }
      
      return maxSoFar;
   }
   
   public static void main(String[] args) {
      try {
         // Step 4: Read input from the file
         int[] inputArray = new int[10];
         File file = new File("phw_input.txt");
         Scanner scanner = new Scanner(file);
         String[] inputLine = scanner.nextLine().split(",");
         for (int i = 0; i < 10; i++) {
            inputArray[i] = Integer.parseInt(inputLine[i]);
         }
         scanner.close();
         
         // Step 5: Print algorithm answers
         System.out.println("algorithm-1:\t" + algorithm1(inputArray));
         System.out.println("algorithm-2:\t" + algorithm2(inputArray));
         System.out.println("algorithm-3:\t" + algorithm3(inputArray, 0, inputArray.length - 1));
         System.out.println("algorithm-4:\t" + algorithm4(inputArray));
         
         // Step 6: Generate random input arrays
         int[][] inputArrays = new int[19][];
         Random random = new Random();
         for (int i = 0, size = 10; i < 19; i++, size += 5) {
            inputArrays[i] = new int[size];
            for (int j = 0; j < size; j++) {
               inputArrays[i][j] = random.nextInt(201) - 100; // Random integers from -100 to 100
            }
         }
         
         // Step 7: Measure average execution times
         int[][] executionTimes = new int[19][4];
         int N = 100; // Number of times to run each algorithm
         for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 4; j++) {
               long startTime = System.nanoTime();
               for (int k = 0; k < N; k++) {
                  switch (j) {
                     case 0:
                        algorithm1(inputArrays[i]);
                        break;
                     case 1:
                        algorithm2(inputArrays[i]);
                        break;
                     case 2:
                        algorithm3(inputArrays[i], 0, inputArrays[i].length - 1);
                        break;
                     case 3:
                        algorithm4(inputArrays[i]);
                        break;
                  }
               }
               long endTime = System.nanoTime();
               executionTimes[i][j] = (int) ((endTime - startTime) / N);
            }
         }
         
         // Step 8: Calculate ceiling(T(n))
         int[][] complexities = new int[19][4];
         for (int i = 0; i < 19; i++) {
            int n = inputArrays[i].length;
            complexities[i][0] = (n * n); // Replace this with the calculated complexity for Algorithm-1
            complexities[i][1] = (n * n); // Replace this with the calculated complexity for Algorithm-2
            complexities[i][2] = (n * log2(n)); // Replace this with the calculated complexity for Algorithm-3
            complexities[i][3] = n; // Replace this with the calculated complexity for Algorithm-4
         }
         
         // Step 9: Write the results to a file
         FileWriter writer = new FileWriter("yourname_phw_output.txt");
         writer.write("algorithm-1,algorithm-2,algorithm-3,algorithm-4,T1(n),T2(n),T3(n),T4(n)\n");
         for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 4; j++) {
               writer.write(executionTimes[i][j] + ",");
            }
            for (int j = 0; j < 4; j++) {
               writer.write(complexities[i][j] + ",");
            }
            writer.write("\n");
         }
         writer.close();
         
         // Step 10: Create a labeled graph
         // Open the "yourname_phw_output.txt" file with a spreadsheet application and create the graph
         // ...
         
      } catch (FileNotFoundException e) {
         e.printStackTrace();
      } catch (IOException e) {
         e.printStackTrace();
      }
   }
   
   // Helper function to calculate log2(n)
   public static int log2(int n) {
      return (int) (Math.log(n) / Math.log(2));
   }
}
   