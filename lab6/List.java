// Rami Alrwais
// raalrwai
// cmps12b
// 5/22/16
// lab6
// List.java
@SuppressWarnings("overrides")
public class List<L> implements ListInterface<L> {
  // private inner Node class
  private class Node {
    L item;
    Node next;
    Node(L x){
      item = x;
      next = null;
    }
  }
  // Fields for the class List
  private Node front; 
  private int numofItems; 
  // List()
  // List Class constructor
  public List(){
    front = null;
    numofItems = 0;
  }
  // find()
  private Node find(int index){
    Node k = front;
    for(int j=1; j<index; j++) 
      k = k.next;
    return k;
  }
  // ADT operations 
  // isEmpty()
  public boolean isEmpty(){
    return(numofItems == 0);
  }
  // size()
  public int size() {
    return numofItems;
  }
  // get()
  public L get(int index) throws ListIndexOutOfBoundsException {
    if( index<1 || index>numofItems ){
      throw new ListIndexOutOfBoundsException(
          "IntegerList Error: get() called on invalid index: " + index);
    }
    Node N = find(index);
    return N.item;
  }
  // add()
  // inserts newItem into this IntegerList at position index
  public void add(int index, L newItem)
    throws ListIndexOutOfBoundsException{
    if( index<1 || index>(numofItems+1) ){
      throw new ListIndexOutOfBoundsException(
          "IntegerList Error: add() called on invalid index: " + index);
    }
    if(index==1){
      Node k = new Node(newItem);
      k.next = front;
      front = k;
    }else{
      Node r = find(index-1); // at this point index >= 2
      Node U = r.next;
      r.next = new Node(newItem);
      r = r.next;
      r.next = U;
    }
    numofItems++;
  }
  // remove()
  // deletes item at position index from this IntegerList
  public void remove(int index)
    throws ListIndexOutOfBoundsException{
    if( index<1 || index>numofItems ){
      throw new ListIndexOutOfBoundsException(
          "IntegerList Error: remove() called on invalid index: " + index);
    }
    if(index==1){
      Node H = front;
      front = front.next;
      H.next = null;
    }else{
      Node P = find(index-1);
      Node H = P.next;
      P.next = H.next;
      H.next = null;
    }
    numofItems--;
  }
  public void removeAll(){
    front = null;
    numofItems = 0;
  }
  // toString()
  // Overrides toString() method
  public String toString(){
    String s = "";
    for(Node O=front; O!=null; O=O.next){
      s += O.item + " ";
    }
    return s;
  }
  @SuppressWarnings("unchecked")
  public boolean equals(Object rhs){
    boolean eq = false;
    List<L> R = null;
    Node N = null;
    Node M = null;

    if(this.getClass()==rhs.getClass()){
      R = (List<L>)rhs;
      eq = (this.numofItems == R.numofItems);

      N = this.front;
      M = R.front;
      while(eq && N!= null){
        eq = (N.item == M.item);
        N = N.next;
        M = M.next;
      }
    }
    return eq;
  }
}
