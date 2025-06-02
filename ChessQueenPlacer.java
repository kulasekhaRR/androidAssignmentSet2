import java.util.*;
public class ChessQueenPlacer{
public List<List<String>> generateBoards(int n){
List<List<String>> solutions=new ArrayList<>();
char[][] board=new char[n][n];
//fill board with empty spaces
for(char[] row:board)
Arrays.fill(row,'.');
//track conflicts using sets
Set<Integer> colSet=new HashSet<>();
Set<Integer> diag1Set=new HashSet<>();
Set<Integer> diag2Set=new HashSet<>();
// Start placing queens row by row
solve(0,n,board,colSet,diag1Set,diag2Set,solutions);
return solutions;
}
private void solve(int row,int size,char[][] layout,Set<Integer> cols,Set<Integer> d1,Set<Integer> d2,List<List<String>> result){
if(row==size){
List<String> snapshot=new ArrayList<>();
for(char[] r:layout)
snapshot.add(String.valueOf(r));
result.add(snapshot);
return;
}
for(int col=0;col<size;col++){
int d1Key=row-col;
int d2Key=row+col;
if(cols.contains(col) || d1.contains(d1Key) || d2.contains(d2Key))
continue; // Unsafe position
layout[row][col]='Q';
cols.add(col);
d1.add(d1Key);
d2.add(d2Key);
solve(row+1,size,layout,cols,d1,d2,result);
// Backtrack
layout[row][col] = '.';
cols.remove(col);
d1.remove(d1Key);
d2.remove(d2Key);
}
}
public static void main(String[] args){
ChessQueenPlacer engine=new ChessQueenPlacer();
Scanner in = new Scanner(System.in);
System.out.print("Enter board size (n): ");
int n=in.nextInt();
List<List<String>> boards=engine.generateBoards(n);
System.out.println("Solutions for " + n + "-Queens:");
int count=1;
for(List<String> board:boards){
System.out.println("Solution "+count++ +":");
for(String row:board)
System.out.println(row);
System.out.println();
}
if(boards.isEmpty())
System.out.println("No possible configurations.");
in.close();
}
}
