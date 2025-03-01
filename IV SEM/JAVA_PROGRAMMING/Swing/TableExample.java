package Swing;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class TableExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Table Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        String[] columnNames = {"Name", "Age", "City"};
        Object[][] data = {
                {"  Akash", 16, "Delhi"},
                {"  Anachal", 12, "Dheradun"},
                {"  Arti", 10, "Mumbai"}
        };

        DefaultTableModel model = new DefaultTableModel(data, columnNames);
        JTable table = new JTable(model);

        JScrollPane scrollPane = new JScrollPane(table);
        frame.add(scrollPane);

        frame.setVisible(true);
    }
}
