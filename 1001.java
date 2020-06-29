import java.util.*;

public class Main {
	public static void main(String[] agrs) {
	    Scanner s = new Scanner(System.in);
	    int groupNumber = s.nextInt();
	    s.nextLine();
	    for (int i = 0; i< groupNumber; ++i) {
	      String str = s.nextLine();
	      int counter = 0;
	      for (int j = 0; j < str.length(); ++j) {
	        if (Character.isDigit(str.charAt(j))) {
	          counter++;
	        }
	      }
	      System.out.println(counter);

	    }
	    s.close();
	  }
		
}