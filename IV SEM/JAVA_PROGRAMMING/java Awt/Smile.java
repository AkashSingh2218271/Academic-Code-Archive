
import java.awt.*;

public class Smile extends Canvas  {
   public void paint(Graphics g) {
          g.drawOval(420, 135, 500, 500);
          g.drawLine(649, 250, 649, 400);
          g.fillOval(500, 250, 110, 110);
          g.fillOval(700, 250, 110, 110);
          g.fillOval(375, 260, 50, 200);
          g.fillOval(915, 260, 50, 200);
          g.drawArc(600, 400, 100, 75, 240, 100);
   }
   public static void main(String args[]) {
        Smile s = new Smile();
        Frame f = new Frame();
        f.add(s);
        f.setTitle("Smile");
        f.setSize(300, 400);
        f.setVisible(true);
   }
}
