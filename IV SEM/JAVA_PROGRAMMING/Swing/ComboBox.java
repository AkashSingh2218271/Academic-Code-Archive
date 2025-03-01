package Swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ComboBox {
    public static void main(String[] args) {
        JFrame frame = new JFrame("ComboBox Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new FlowLayout());

        JLabel label = new JLabel("Select an item:");

        String[] items = {"Item 1", "Item 2", "Item 3", "Item 4"};
        JComboBox<String> comboBox = new JComboBox<>(items);

        comboBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedItem = (String) comboBox.getSelectedItem();
                JOptionPane.showMessageDialog(frame, "Selected item: " + selectedItem);
            }
        });

        frame.add(label);
        frame.add(comboBox);

        // Make the frame visible
        frame.setVisible(true);
    }
}
