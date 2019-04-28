/**
 * @program: Homework4
 * @description: Main function for Q1
 * @author: Zekun Zhang
 * @create: 2019-04-26 22:31
 */

public class Main {
    public static void main(String[] args) {
        DataReader dataReader = new DataReader();
        if(args.length != 1){
            System.out.println("Error: data needed.");
            System.exit(1);
        }

        Graph graph = dataReader.Reader(args[0]);

        CheckCycle checker = new CheckCycle(graph);

        if(checker.isAcyclic()){
            System.out.println("The graph is acyclic.");
        } else {
            System.out.println("The graph is cyclic.");
        }

    }
}
