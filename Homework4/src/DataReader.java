/**
 * @program: Homework4
 * @description: Data reader from .txt to construct a new graph
 * @author: Zekun Zhang
 * @create: 2019-04-26 00:07
 */

import java.io.*;

public class DataReader {
    /**
     * @Description: function to read .txt file and construct a new graph and return
     * @Param: [path]
     * @return: Graph
     * @Author: Zekun Zhang
     * @Date: 2019-04-26
     */

    public Graph Reader(String path) {
        Graph graph = null;
        try {
            File file = new File(path);
            FileInputStream fileStream = new FileInputStream(file);
            InputStreamReader inputStream = new InputStreamReader(fileStream);
            BufferedReader bufferedReader = new BufferedReader(inputStream);
            String line = null;
            try {
                line = bufferedReader.readLine();
                graph = new Graph(Integer.parseInt(line));
                line = bufferedReader.readLine();
                int E = Integer.parseInt(line);

                while ((line = bufferedReader.readLine()) != null) {
                    String[] s = line.split(" ");
                    int v = Integer.parseInt(s[0]);
                    int w = Integer.parseInt(s[1]);
                    graph.addEdge(v, w);
                }
                bufferedReader.close();
                inputStream.close();
            } catch (IOException e) {
                System.out.println(e.toString());
            }

        } catch (FileNotFoundException e) {
            System.out.println(e.toString());
        }
        return graph;
    }
}
