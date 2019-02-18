//Rami Alrwais
//raalrwai
//cmps12b
//4/24/16
//Dictionary ADT which takes in two values a string and a key
//and performs several different operations on them
public class Dictionary implements DictionaryInterface{

  // private class Node
  // takes a  string key and value  
  // creates a structure for a linked list  
    
  private class Node{
    String key;
    String value;
    Node next;
    //Constructor for node
    Node(String key, String value){
      this.key = key;
      this.value = value;
      next = null;
    }
  }
  //private feild 
  private Node front, back;
  private int numItems;
  //initializes the private feild
  public Dictionary(){
    front = null;
    numItems = 0;
    back = null;
  }
  //findkey returns reference where key is or returns null
  //if no key is found
  private Node findKey(String key){
    Node N = front;
    while(N != null){
      if(N.key.equals(key)){
        return N; 
      }
      else{
        N = N.next; 
      }
    }
    return null;
  }
  //IsEmpty Returns true if Dictionary is empty or false
  public boolean isEmpty(){
    return (numItems==0);
  }
  /*size
   *Pre:None
   *Pos:returns the number of items in linked list
   */
  public int size(){
    return numItems;
  }
  //returns value linked to key or returns null if key is not in list
  public String lookup(String key){
    Node N = front;
    while(N != null){
      if(key.equals(N.key))
        break;
      N = N.next;
    } 
    if(N == null){
      return null;
    }else{
      return  N.value; 
    }
  }//insert takes in a key and a value and places them in the list otherwise
  //throws a duplicate key exception if they are already in list
  public void insert(String key, String value){
    if(lookup(key) != null)
      throw new DuplicateKeyException("cannot insert duplicate key"); 
    if (numItems == 0){
      front = back = new Node(key,value);
    }else{
      Node N = new Node(key, value);
      back.next = N;
      back = N;
    }
    numItems++; 
  }
  //removes key and value from list
  public void delete(String key){
    if( lookup(key) == null){
      throw new KeyNotFoundException("cannot delete non-existent key");
    } else {
      if(numItems <= 1){
        Node N = front;
        front = front.next;
        N.next = null;
        numItems--;
      } else {
        Node N = front;
        if(N.key.equals(key)){
          front = N.next;
          numItems--;
        } else {
          while(!N.next.key.equals(key)) {
            N = N.next;
          }
          N.next = N.next.next;
          numItems--;
        }
      }
    }
  }
  //Empties linked list
  public void makeEmpty(){
    front = null;
    numItems = 0;
  }
  //print the values of the linked lists as strings
  public String toString(){
    String s = "";
    Node N = front;
    while( N != null){
      s += N.key + " " + N.value + "\n"; 
      N = N.next;
    }
    return s;
  }
}//end of ADT
