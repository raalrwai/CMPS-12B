//Rami Alrwais
//raalrwai
//cmps12b
//5/11/16
//pa4
//Simulation.java
import java.io.*;
import java.util.Scanner;
public class Simulation{
 //function getjob
  public static Job getJob(Scanner in){
    String[] s = in.nextLine().split(" ");
    int b = Integer.parseInt(s[0]);
    int c = Integer.parseInt(s[1]);
    return new Job(b, c);
  }
  public static void main(String[] args) throws IOException{
  //variable initializations
    Scanner filein = null;
    PrintWriter rprt = null;
    PrintWriter trc = null;
    String line = null;
    String numofJobs = null;
    int m, time = 0; 
    Queue storageCopy = new Queue();
    Queue storage = new Queue();
    Queue end = new Queue();
    Job j = null;
    Queue[] processorQueues = null;
    if(args.length < 1){
      System.out.println("Usage: Simulation infile");
      System.exit(1);
    }
    filein = new Scanner(new File(args[0]));
    rprt = new PrintWriter(new FileWriter(args[0] + ".rpt"));
    trc = new PrintWriter(new FileWriter(args[0] + ".trc"));
    numofJobs = filein.nextLine();
    m = Integer.parseInt(numofJobs);
    while (filein.hasNext()){
      j = getJob(filein);
      storageCopy.enqueue(j);
    }
    trc.println("Trace file: " + (args[0] + ".trc"));
    trc.println(m + " Jobs:");
    trc.println(storageCopy.toString());
    trc.println();
    rprt.println("Report file: " + (args[0] + ".rpt"));
    rprt.println(m + " Jobs:");
    rprt.println(storageCopy.toString());
    rprt.println();
    rprt.print("*****************************************************************************");
    //for loop to run simulation
    for(int n = 1; n < m; n++){ 
      int totalWait = 0;
      int maxWait = 0;
      double avgWait = 0.00;
      for(int i = 1; i<storageCopy.length()+1; i++){
        j = (Job)storageCopy.dequeue();
        j.resetFinishTime();
        storage.enqueue(j);
        storageCopy.enqueue(j);
      } //empty queue processor used to place storage
      int processors = n;
      processorQueues = new Queue[n+2];
      processorQueues[0] = storage;
      processorQueues[n+1] = end;
      for (int i = 1; i < n+1; i++){
        processorQueues[i] = new Queue();
      } //print for each run of loop
      trc.println("*****************************");
      if(processors==1){
        trc.println(processors + " processor:");
      }else{
        trc.println(processors + " processors:");
      }
      trc.println("*****************************");
      trc.println("time=" + time);
      trc.println("0: " + storage.toString());
      for(int i = 1; i < processors+1; i++){
        trc.println(i + ": " + processorQueues[i]);
      }

      while(end.length()!=m){ 
         //declaratins used in body of while loop
        int compFinal = Integer.MAX_VALUE;
        int finalIndex = 1; 
        int comp = -1;
        int length = -1;
        int finalLength = -1;
        Job compare = null;
        if(!storage.isEmpty()){
          compare = (Job)storage.peek();
          compFinal = compare.getArrival();
          finalIndex = 0;
        }
        for(int i = 1; i < processors+1; i++){ 
          if(processorQueues[i].length() != 0){
            compare = (Job)processorQueues[i].peek();
            comp = compare.getFinish();
          }
          if(comp == -1){
          }else if(comp<compFinal){ 
            compFinal = comp;
            finalIndex = i;
          }
          time = compFinal;
        }
        if(finalIndex == 0){ //movefrom storage with shortest length
          int tempIndex = 1;
          finalLength = processorQueues[tempIndex].length(); 
          for(int i = 1; i < processors+1; i++){
            length = processorQueues[i].length();
            if(length<finalLength){
              finalLength = length;
              tempIndex = i;
            }
          }
          compare = (Job)storage.dequeue();
          processorQueues[tempIndex].enqueue(compare);
          if(processorQueues[tempIndex].length()==1){
            compare = (Job)processorQueues[tempIndex].peek();
            compare.computeFinishTime(time);
          }
        }
        else{//move from processor to finish
          compare = (Job)processorQueues[finalIndex].dequeue();
          end.enqueue(compare);
          int tempWait = compare.getWaitTime();
          if(tempWait > maxWait){
            maxWait = tempWait;
          }
          totalWait += tempWait;
          if(processorQueues[finalIndex].length() >= 1){
            compare = (Job)processorQueues[finalIndex].peek();
            compare.computeFinishTime(time);
          }
        }
        trc.println();
        trc.println("time=" + time);
        trc.println("0: " + storage.toString());
        for(int i = 1; i < processors+1; i++){
          trc.println(i + ": " + processorQueues[i]);
        }
        trc.println("finished: " + end.toString());
      }//computing the total wait
      avgWait = (double)Math.round(avgWait*100)/100;
      trc.println();
      rprt.println();
      if(processors==1){
        rprt.print(processors + " processor: totalWait=" + totalWait + ", maxWait=" + maxWait + ", averageWait=" + avgWait);
      }else{
        rprt.print(processors + " processors: totalWait=" + totalWait + ", maxWait=" + maxWait + ",averageWait=" + avgWait);
      }
      time = 0;
      end.dequeueAll();//end of body of loop
    }
    filein.close();//closes both report and trace files
    rprt.close();
    trc.close();
  }
}
