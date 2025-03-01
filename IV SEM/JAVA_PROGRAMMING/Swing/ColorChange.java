package Swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ColorChange extends Frame implements ActionListener {
    private TextField tf;
    private Button b;

    public ColorChange() {
        FlowLayout layout = new FlowLayout();
        setLayout(layout);

        tf = new TextField("", 10);
        tf.setEditable(true);

        b = new Button("OK");
        add(tf);
        add(b);
        b.addActionListener(this);

        setTitle("Color Change");
        setSize(400, 400);
        setVisible(true);
    }

    public static void main(String[] args) {
        new ColorChange();
    }

    public void actionPerformed(ActionEvent evt) {
        String inputColor = tf.getText().toUpperCase();
        Color bgColor;

        switch (inputColor) {
            case "PINK":
                bgColor = Color.PINK;
                break;
            case "RED":
                bgColor = Color.RED;
                break;
            case "ORANGE":
                bgColor = Color.ORANGE;
                break;
            case "YELLOW":
                bgColor = Color.YELLOW;
                break;
            default:
                bgColor = Color.BLACK;
        }

        setBackground(bgColor);
    }
}
