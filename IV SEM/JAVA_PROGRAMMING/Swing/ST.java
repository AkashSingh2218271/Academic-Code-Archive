package Swing;
import java.awt.*;
import javax.swing.*;

public class ST extends JFrame {
    ST() {
        setLayout(new FlowLayout());
        String s[] = {"India", "USA", "UK"};
        JComboBox<String> cb = new JComboBox<>(s);
        add(cb);
    }
    

    public static void main(String args[]) {
        ST st = new ST();
        st.setSize(300, 400);
        st.setVisible(true);
    }
}
