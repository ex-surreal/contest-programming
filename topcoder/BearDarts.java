import java.util.Map;
import java.util.TreeMap;

public class BearDarts {
	public long count(int[] w) {
		long ret = 0;
		TreeMap cnt = new TreeMap ();
		for (int i = 0; i < w.length; i ++) {
			for (int j = i+1; j < w.length; j ++) {
				int g = new Integer(w[i]).gcd(w[j]);
				Point key = new Point(w[i]/g, w[j]/g);
				if (cnt.containsKey(key)) {
					ret += cnt.get(key);
				}
			}
			for (int j = 0; j < i; j ++) {
				int g = Math.gcd(w[i], w[j]);
				Point key = new Point(w[i]/g, w[j]/g);
				if (cnt.containsKey(key)) {
					cnt.replace(key, cnt.get(key) + 1);
				} else {
					cnt.put(key, 1);
				}
			}
		}
		return ret;
	}


// BEGIN CUT HERE
	public static void main(String[] args) {
		if (args.length == 0) {
			BearDartsHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				BearDartsHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}

// BEGIN CUT HERE
class BearDartsHarness {
	public static void run_test(int casenum) {
		if (casenum != -1) {
			if (runTestCase(casenum) == -1)
				System.err.println("Illegal input! Test case " + casenum + " does not exist.");
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = runTestCase(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			System.err.println("No test cases run.");
		} else if (correct < total) {
			System.err.println("Some cases FAILED (passed " + correct + " of " + total + ").");
		} else {
			System.err.println("All " + total + " tests passed!");
		}
	}
	
	static boolean compareOutput(long expected, long result) { return expected == result; }
	static String formatResult(long res) {
		return String.format("%d", res);
	}
	
	static int verifyCase(int casenum, long expected, long received) { 
		System.err.print("Example " + casenum + "... ");
		if (compareOutput(expected, received)) {
			System.err.println("PASSED");
			return 1;
		} else {
			System.err.println("FAILED");
			System.err.println("    Expected: " + formatResult(expected)); 
			System.err.println("    Received: " + formatResult(received)); 
			return 0;
		}
	}

	static int runTestCase(int casenum__) {
		switch(casenum__) {
		case 0: {
			int[] w                   = {6,8,4,3,6};
			long expected__           = 2;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}
		case 1: {
			int[] w                   = {3,4,12,1};
			long expected__           = 0;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}
		case 2: {
			int[] w                   = {42,1000000,1000000,42,1000000,1000000};
			long expected__           = 3;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}
		case 3: {
			int[] w                   = {1,1,1,1,1};
			long expected__           = 5;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}
		case 4: {
			int[] w                   = {1,2,3,4,5,6,5,4,3,2,1};
			long expected__           = 22;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}
		case 5: {
			int[] w                   = {33554432, 33554432, 67108864, 134217728};
			long expected__           = 0;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}

		// custom cases

/*      case 6: {
			int[] w                   = ;
			long expected__           = ;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}*/
/*      case 7: {
			int[] w                   = ;
			long expected__           = ;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}*/
/*      case 8: {
			int[] w                   = ;
			long expected__           = ;

			return verifyCase(casenum__, expected__, new BearDarts().count(w));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
