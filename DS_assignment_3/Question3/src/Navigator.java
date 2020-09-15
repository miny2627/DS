import java.awt.*;
import javax.swing.*;

class MyFrame extends JFrame
{
	public MyFrame()
	{
		setSize(1000,1000);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Navigator");
		
		JButton b1=new JButton("Generate Random Road");
		JButton b2=new JButton("Find Shortest Path");
		JButton b3=new JButton("Get MST");
		
		this.add(b1, BorderLayout.EAST);
		this.add(b2, BorderLayout.EAST);
		this.add(b3, BorderLayout.EAST);
		
		setVisible(true);
	}
}
public class Navigator{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyFrame m=new MyFrame();

	}

}
