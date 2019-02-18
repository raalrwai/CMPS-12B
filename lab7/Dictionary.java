//Rami Alrwais
//raalrwai
//cmps12b
//lab7
//Dictionary.java
public class Dictionary implements DictionaryInterface{


  // NodeObj
  private class Node{
    String key;
    String value;
    Node l;
    Node r;

    // constructor for private Node type
    Node(String k, String v) {
      key = k;
      value = v;
     l = r = null;
    }
  } 

  private Node root;
  private int numofPairs;

  public Dictionary(){
    root = null;
    numofPairs = 0;
  } 


  // returns the Node containing key k in the subtree rooted at R, or returns
  // NULL if no such Node exists
  Node findKey(Node R, String key){
    if(R==null || (key.equals(R.key)))
      return R;
    if( (key.compareTo(R.key)<0 )) 
      return findKey(R.l, key);
    else 
      return findKey(R.r, key);
  }


  // returns the parent of N in the subtree rooted at R, or returns NULL 
  Node findParent(Node N, Node R){
    Node P = null;
    if( N!=R ){
      P = R;
      while( P.l!=N && P.r!=N ){
        if((N.key.compareTo(P.key)<0))
          P = P.l;
        else
          P = P.r;
      }
    }   
    return P;
  }

  // returns the leftmost Node in the subtree rooted at R, or NULL if R is NULL.
  Node findLeftmost(Node R){
    Node L = R;
    if( L!=null ) for( ; L.l!=null; L=L.l);
    return L;
  }

  // of increasing keys to file pointed to by out.
  String printInOrder(Node R){
    String S = ""; 
    if( R!=null ){
      S += printInOrder(R.l);
      S += R.key + " " + R.value + "\n";
      S +=  printInOrder(R.r);
    }
    return S; 
  }

  // deletes all Nodes in the subtree rooted at N.
  void deleteAll(Node N){
    if( N!=null ){
      deleteAll(N.l);
      deleteAll(N.r);
    } 
  }
  // returns 1 (true) if S is empty, 0 (false) otherwise
  // pre: none
  public boolean isEmpty(){
    return (numofPairs == 0);
  }

  // returns the number of (key, value) pairs in D
  // pre: none
  public int size() {
    return(numofPairs);
  } 

  // returns the value v such that (k, v) is in D, or returns NULL if no 
  // such value v exists.
  public String lookup(String key){
    Node N = findKey(root, key);
    return ( N==null ? null : N.value );
  }

  // inserts new (key,value) pair into D
  public void insert(String key, String value) throws DuplicateKeyException{
    if( findKey(root, key)!=null ){
      throw new DuplicateKeyException("Cannot insert duplicate key");
    }
    Node N = new Node(key, value);
    Node B = null;
    Node A = root;
    while( A!=null ){
      B = A;
      if( key.compareTo(A.key)<0 ) 
        A = A.l;
      else A =  A.r;
    }
    if( B==null ) 
      root = N;
    else if( key.compareTo(B.key)<0 ) 
      B.l = N;
    else B.r = N;
    numofPairs++;
  }

  // deletes pair with the key k
  public void delete(String key) throws KeyNotFoundException{
    Node N = findKey(root, key);
    Node P;
    Node S;
    if( N==null ){
      throw new KeyNotFoundException("Cannot delete non-existent keys");
    }
    if( N.l==null && N.r==null ){  
      if( N==root ){
        root = null;
      }else{
        P = findParent(N, root);
        if( P.r==N ) P.r = null;
        else P.l = null;
      }
    }else if( N.r==null ){            
      if( N==root ){
        root = N.l;
      }else{
        P = findParent(N, root);
        if( P.r==N ) P.r = N.l;
        else P.l = N.l;
      }
    }else if( N.l==null ){            
      if( N==root ){
        root = N.r;
      }else{
        P = findParent(N, root);
        if( P.r==N ) P.r = N.r;
        else P.l = N.r;
      }
    }else{  
      S = findLeftmost(N.r);
      N.key = S.key;
      N.value = S.value;
      P = findParent(S, N);
      if( P.r==S ) P.r = S.r;
      else P.l = S.r;
    }
    numofPairs--;
  }

  // re-sets D to the empty state.
  public void makeEmpty(){
    deleteAll(root);
    root = null;
    numofPairs = 0;
  }

  // prints a text representation of D to the file pointed to by out
  public String toString(){
    Node N = root;
    return printInOrder(N);
  }   
} 
