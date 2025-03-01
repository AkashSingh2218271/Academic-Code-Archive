import java.awt.FlowLayout;
import javax.swing.*;

class SwingTabular extends JFrame {
    SwingTabular() {
        setLayout(new FlowLayout());
        String s[] = {"India", "USA", "UK"};
        JComboBox<String> cb = new JComboBox<>(s);
        add(cb);
    }
    
}
public class TabularForm {

    public static void main(String args[]) {
        SwingTabular st = new SwingTabular();
        st.setSize(300, 400);
        st.setVisible(true);
    }
}
