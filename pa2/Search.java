//Rami ALrwais
//raalrwai
//cs12b
//pa2
//Search.java
//4/17/16
//
//argument
import java.io.*;//imports java classes so we are able to write methods
import java.util.Scanner;

public class Search{
  public static void main(String[] args) throws IOException{ 
    if(args.length < 2){//prints usage message when incoorect input is given
      System.err.println("Usage: Search file target1 [target2 ..]");
      System.exit(1);//exits program
    } //declares variables and arrays used in program


    String L = null;//sets L to unassigned
    Scanner file = null;//sets user input file to unassigned
    int linecount = 0;//sets linecount to 0
    int[] lineLocation = null;//sets linelocatoin to null
    String[] words = null;
    //declares command line argument 0 as fileInput
    file = new Scanner(new File(args[0]));
    //Counts the number of ines in given file
    while( file.hasNextLine() ){linecount++;
      L = file.nextLine();

    }
    //initializez length of token and array linenumber
    words = new String[linecount];
    lineLocation = new int[linecount];
    file = new Scanner(new File(args[0]));
    //iterates through the file adding number to the declared array
    for(int i=1; i<=lineLocation.length; i++)
      lineLocation[i-1] = i;
    for(int i =0; file.hasNextLine(); i++){
      L = file.nextLine();
      words[i] = L;
    }
    //gives a call to mergeSort method to arrange the string in order
    mergeSort(words,lineLocation, 0, words.length-1);
    //if target is found, target is printed with line number
    for(int i=1; i<args.length; i++){
      System.out.println( binarySearch(words, lineLocation, 0, words.length-1, args[i]));
    }
    file.close();

  }

  //mergeSort()
  //sort subarray A[p...r] 
  static void mergeSort(String[] word, int[] lineLocation, int p, int r){
    int q;
    if(p < r){//checks if p<r and executes 
      q = (p+r)/2;//splits array in two
      mergeSort(word, lineLocation, p, q);//recursiely sorts subbaray
      mergeSort(word, lineLocation, q+1, r);
      merge(word, lineLocation, p, q, r);

    }
  }
  //merge
  //takes two Arrays and two integers p and r and
  //changes the order of the Array putting them in lexical order
  static void merge(String[] word, int[] lineLocation, int p, int q, int r){
    int w1 = q-p+1;
    int w2 = r-q;
    String[] one = new String[w1];
    String[] two = new String[w2];
    int[] L = new int[w1];
    int[] R = new int[w2];
    int i, j, z;

    for(i=0; i<w1; i++){ one[i] = word[p+i];///iterates through first half of 
      L[i] = lineLocation[p+i];
    }
    for(j=0; j<w2; j++){ two[j] = word[q+j+1];//iterates through second half
      R[j] = lineLocation[q+j+1];
    }
    i = 0; j = 0;
    for(z=p; z<=r; z++){
      if( i<w1 && j<w2){
        if( one[i].compareTo(two[j])>0 ){word[z] = one[i];
          lineLocation[z] = L[i];
          i++;//increments
        }
        else{word[z] = two[j];
          lineLocation[z] = R[j];
          j++;//increments
        }
      }
      else if( i<w1){word[z] = one[i];
        lineLocation[z] = L[i];
        i++;//increments
      }
      else{ word[z] = two[j];
        lineLocation[z] = R[j];
        j++;//increments
      }
    }
  }
  //binarySearch
  //searches file for word and if found returns the line the word was on
  public static String binarySearch(String[] word, int[] lineLocation, int p, int r, String goal){
    int q;
    if( p == r ){//checks if array only contains one element
      return goal + " not found";//returns word with statement when not found
    }
    else{
      q = (p+r)/2;
      if( word[q].compareTo(goal)==0){//splits array in two to search for word
        return goal + " found on line " + lineLocation[q];
        // return goal + " found on line " + lineNumber[q];
      }
      else if( word[q].compareTo(goal)<0 ) {
        return binarySearch(word, lineLocation, p, q, goal);
      }
      else{
        return binarySearch(word, lineLocation, q+1, r, goal);
      }
    }
  }
}
