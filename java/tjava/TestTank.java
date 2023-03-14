/*
 * copyright
 */
import java.util.*;
/** 
 * description
 */
class Tank {
	int level;
}
public class TestTank {
	public static void main(String[] args) {
		Tank t1 = new Tank();
		Tank t2 = new Tank();
		t1.level = 9;
		t2.level = 100;
		System.out.println("1: " + t1.level);
		System.out.println("2: " + t2.level);
		System.out.println("--- ta = t2 ---");
		t2 = t1;
		t1.level = 20;
		System.out.println("1: " + t1.level);
		System.out.println("2: " + t2.level);
	}
}
