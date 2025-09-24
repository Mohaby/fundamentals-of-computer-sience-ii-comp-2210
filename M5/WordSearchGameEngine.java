import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.lang.Math;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * Creates a word search game.
 *
 * @author Mohab YOusef (mey0012@auburn.edu)
 *
 */

public class WordSearchGameEngine implements WordSearchGame
{
   private TreeSet<String> wordTree;
   private String[][] gameBoard; 
   private int width;
   private int height;
   private boolean[][] hasChecked;
   private ArrayList<Integer> wordPath;
   private static final int MAX_ADJACENT = 8; 
   private String currentWord;
   private SortedSet<String> wordSet; 
   private ArrayList<Position> allWordPath;
   public WordSearchGameEngine(){
      wordTree = null;
      gameBoard = new String[4][4];
      gameBoard[0][0] = "E";
      gameBoard[0][1] = "E";
      gameBoard[0][2] = "C";
      gameBoard[0][3] = "A";
      gameBoard[1][0] = "A";
      gameBoard[1][1] = "L";
      gameBoard[1][2] = "E";
      gameBoard[1][3] = "P";
      gameBoard[2][0] = "H";
      gameBoard[2][1] = "N";
      gameBoard[2][2] = "B";
      gameBoard[2][3] = "O";
      gameBoard[3][0] = "Q";
      gameBoard[3][1] = "T";
      gameBoard[3][2] = "T";
      gameBoard[3][3] = "Y";
      width = gameBoard.length;
      height = gameBoard[0].length;
      markAllUnchecked();
   }
    /**
     * Loads the lexicon into a data structure for later use. 
     * 
     * @param fileName A string containing the name of the file to be opened.
     * @throws IllegalArgumentException if fileName is null
     * @throws IllegalArgumentException if fileName cannot be opened.
     */
   public void loadLexicon(String fileName) {
      wordTree = new TreeSet<String>();
      if (fileName == null) {
         throw new IllegalArgumentException();
      }
      try {
         Scanner scan = new Scanner(new BufferedReader(new FileReader(new
            File(fileName))));
         while (scan.hasNext()){
            String str = scan.next();
            str = str.toUpperCase(); 
            wordTree.add(str); 
            scan.nextLine();
         } 
      }
      catch (java.io.FileNotFoundException e){
         throw new IllegalArgumentException();
      } 
   }
  /**
     * Stores the incoming array of Strings in a data structure that will make
     * it convenient to find words.
     * 
     * @param letterArray This array of length N^2 stores the contents of the
     *     game board in row-major order. Thus, index 0 stores the contents of board
     *     position (0,0) and index length-1 stores the contents of board position
     *     (N-1,N-1). Note that the board must be square and that the strings inside
     *     may be longer than one character.
     * @throws IllegalArgumentException if letterArray is null, or is  not
     *     square.
     */
   public void setBoard(String[] letterArray) {
      if (letterArray == null) {
         throw new IllegalArgumentException();
      }
      int n = (int)Math.sqrt(letterArray.length);
      if ((n * n) != letterArray.length){
         throw new IllegalArgumentException();
      }
      gameBoard = new String[n][n];
      width = n;
      height = n;
      int index = 0;
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            gameBoard[i][j] = letterArray[index];
            index++; 
         }
      }
      markAllUnchecked();
   }
   /**
     * Creates a String representation of the board, suitable for printing to
     *   standard out. Note that this method can always be called since
     *   implementing classes should have a default board.
     */
   public String getBoard() {
      String stringBoard = "";
      for (int i = 0; i < height; i ++) {
         if (i > 0) {
            stringBoard += "\n";
         }
         for (int j = 0; j < width; j++) {
            stringBoard += gameBoard[i][j] + " ";
         } }
      return stringBoard;
   }
   /**
     * Retrieves all scorable words on the game board, according to the stated game
     * rules.
     * 
     * @param minimumWordLength The minimum allowed length (i.e., number of
     *     characters) for any word found on the board.
     * @return java.util.SortedSet which contains all the words of minimum length
     *     found on the game board and in the lexicon.
     * @throws IllegalArgumentException if minimumWordLength < 1
     * @throws IllegalStateException if loadLexicon has not been called.
     */
   public SortedSet<String> getAllScorableWords(int minimumWordLength) {
      if (minimumWordLength < 1) {
         throw new IllegalArgumentException();
      }
      if (wordTree == null) {
         throw new IllegalStateException();
      }
      allWordPath = new ArrayList<Position>();
      wordSet = new TreeSet<String>();
      currentWord = "";
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j ++) {
            currentWord = gameBoard[i][j];
            if (isValidWord(currentWord) && currentWord.length() >= minimumWordLength) {
               wordSet.add(currentWord);
            }
            if (isValidPrefix(currentWord)) {
               Position temp = new Position(i,j);
               allWordPath.add(temp);
               dfs2(i, j, minimumWordLength);
               allWordPath.remove(temp);
            } }
      }
      return wordSet;
   }
   private void dfs2(int x, int y, int min)
   {
      Position start = new Position(x, y);
      markAllUnchecked();
      markPathVisited();
      for (Position p : start.neighbors()) {
         if (!isVisited(p)) {
            visit(p); 
            if (isValidPrefix(currentWord + gameBoard[p.x][p.y])) {
               currentWord += gameBoard[p.x][p.y];
               allWordPath.add(p);
               if (isValidWord(currentWord) && currentWord.length() >= min) {
                  wordSet.add(currentWord);
               }
               dfs2(p.x, p.y, min);
               allWordPath.remove(p);
               int endIndex = currentWord.length() - gameBoard[p.x]
                  [p.y].length();
               currentWord = currentWord.substring(0, endIndex);
            } }
      }
      markAllUnchecked();
      markPathVisited();
   }
   /**
     * Determines if the given word is in the lexicon.
     * 
     * @param wordToCheck The word to validate
     * @return true if wordToCheck appears in lexicon, false otherwise.
     * @throws IllegalArgumentException if wordToCheck is null.
     * @throws IllegalStateException if loadLexicon has not been called.
     */
   public int getScoreForWords(SortedSet<String> words, int minimumWordLength)
   {
      if (minimumWordLength < 1) {
         throw new IllegalArgumentException();
      }
      if (wordTree == null) {
         throw new IllegalStateException();
      }
      int score = 0;
      Iterator<String> itr = words.iterator();
      while (itr.hasNext()) {
         String word = itr.next();
         if (word.length() >= minimumWordLength && isValidWord(word) && ! isOnBoard(word).isEmpty()) {
            score += (word.length() - minimumWordLength) + 1;
         } }
      return score;
   }
   /**
     * Determines if there is at least one word in the lexicon with the 
     * given prefix.
     * 
     * @param prefixToCheck The prefix to validate
     * @return true if prefixToCheck appears in lexicon, false otherwise.
     * @throws IllegalArgumentException if prefixToCheck is null.
     * @throws IllegalStateException if loadLexicon has not been called.
     */
   public boolean isValidWord(String wordToCheck)
   {
      if (wordTree == null) {
         throw new IllegalStateException();
      }
      if (wordToCheck == null) {
         throw new IllegalArgumentException();
      }
      wordToCheck = wordToCheck.toUpperCase();
      return wordTree.contains(wordToCheck); 
   }
    /**
     * Determines if there is at least one word in the lexicon with the 
     * given prefix.
     * 
     * @param prefixToCheck The prefix to validate
     * @return true if prefixToCheck appears in lexicon, false otherwise.
     * @throws IllegalArgumentException if prefixToCheck is null.
     * @throws IllegalStateException if loadLexicon has not been called.
     */      
   public boolean isValidPrefix(String prefixToCheck) {
      if (wordTree == null) {
         throw new IllegalStateException();
      }
      if (prefixToCheck == null) {
         throw new IllegalArgumentException();
      }
      prefixToCheck = prefixToCheck.toUpperCase(); 
      String word = wordTree.ceiling(prefixToCheck);
      if (word != null) {
         return word.startsWith(prefixToCheck);
      }
      return false;
   }
    /**
     * Determines if the given word is in on the game board. If so, it returns
     * the path that makes up the word.
     * @param wordToCheck The word to validate
     * @return java.util.List containing java.lang.Integer objects with  the path
     *     that makes up the word on the game board. If word is not on the game
     *     board, return an empty list. Positions on the board are numbered from zero
     *     top to bottom, left to right (i.e., in row-major order). Thus, on an NxN
     *     board, the upper left position is numbered 0 and the lower right position
     *     is numbered N^2 - 1.
     * @throws IllegalArgumentException if wordToCheck is null.
     * @throws IllegalStateException if loadLexicon has not been called.
     */
   public List<Integer> isOnBoard(String wordToCheck) {
      if (wordToCheck == null) {
         throw new IllegalArgumentException();
      }
      if (wordTree == null) {
         throw new IllegalStateException();
      }
      allWordPath = new ArrayList<Position>(); 
      wordToCheck = wordToCheck.toUpperCase(); 
      currentWord = ""; 
      wordPath = new ArrayList<Integer>(); 
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j ++)
         {
            if (wordToCheck.equals(gameBoard[i][j])) {
               wordPath.add(i * width + j); 
               return wordPath;
            }
            if (wordToCheck.startsWith(gameBoard[i][j]))
            {
               Position pos = new Position(i, j);
               allWordPath.add(pos); 
               currentWord = gameBoard[i][j]; 
               dfs(i, j, wordToCheck); 
               if (!wordToCheck.equals(currentWord)) {
                  allWordPath.remove(pos);
               } else {
                  for (Position p: allWordPath) { 
                     wordPath.add((p.x * width) + p.y); 
                  } 
                  return wordPath;
               }
            } }
      }
      return wordPath;
   }


   private void dfs(int x, int y, String wordToCheck) {
      Position start = new Position(x, y); 
      markAllUnchecked();
      markPathVisited();
      for (Position p : start.neighbors()) {
         if (!isVisited(p))  {
            visit(p); 
            if (wordToCheck.startsWith(currentWord + gameBoard[p.x][p.y])) {
               currentWord += gameBoard[p.x][p.y]; 
               allWordPath.add(p); 
               dfs(p.x, p.y, wordToCheck); 
               if (wordToCheck.equals(currentWord))                {
                  return; //exit
               } else {
                  allWordPath.remove(p);
                  int endIndex = currentWord.length() - gameBoard[p.x]
                     [p.y].length();
                  currentWord = currentWord.substring(0, endIndex);
               }
            } }
      }
      markAllUnchecked();
      markPathVisited();
   }
   private void markAllUnchecked()
   {
      hasChecked = new boolean[width][height];
      for (boolean[] row : hasChecked)
      { Arrays.fill(row, false); 
      } 
   }
   private void markPathVisited()
   {
      for (int i = 0; i < allWordPath.size(); i ++)
      { visit(allWordPath.get(i)); } 
   }

   private class Position
   {
      int x; int y;
      public Position(int x, int y)
      {
         this.x = x; 
         this.y = y; 
      }
      @Override
      public String toString()
      {
         return "(" + x + ", " + y + ")"; }      
      public Position[] neighbors() {
         Position[] neighbrs = new Position[MAX_ADJACENT];
         int count = 0;
         Position p;
         for (int i = -1; i <= 1; i++)
         {
            for (int j = -1; j <= 1; j++)
            {
               if (!((i == 0) && (j == 0)))
               {
                  p = new Position(x + i, y + j); 
                  if (isValid(p)) 
                  { neighbrs[count++] = p; } 
               }
            } }
         return Arrays.copyOf(neighbrs, count); 
      }
   }
   private boolean isValid(Position p)  
   {
      return (p.x >= 0) && (p.x < width) && (p.y >= 0) && (p.y < height); }
   private boolean isVisited(Position p)   {
      return hasChecked[p.x][p.y]; }
   private void visit(Position p)
   { hasChecked[p.x][p.y] = true; }
}




