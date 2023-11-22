/*
 * test Package
 */
import java.util.*;

class pub_class {
		int i;
		public void func() {
			System.out.println("public" + i);
		}
	}
class non_pub_class	{
	int j;
	public void func() {
		System.out.println("private" + j);
	}
}
public class MyPackage {
	public static void main(String[] args) {
		pub_class p = new pub_class();
		non_pub_class np = new non_pub_class();

		p.func();
		np.func();
		System.out.println("package\n");
	}
}
