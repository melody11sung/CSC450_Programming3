package Portfolio;

public class Portfolio {
	
	
	public static void main(String[] args) {
		
		// new Counter object, with default count=0
		Counter counter = new Counter(0);
		
		// new threads that does Counter_up and Counter_down
		Thread t1 = new Thread(new Counter_up(counter, 20));
		Thread t2 = new Thread(new Counter_down(counter, 20));
		
		t1.start();
		try {
			t1.join();
		}catch (InterruptedException e){
			t1.currentThread().interrupt();
		}
		
		t2.start(); // After t1 is done and joined, t2 starts
		try {
			t2.join();
		}catch (InterruptedException e){
			t2.currentThread().interrupt();
		}
	}
	
	// Counter class that has increment, decrement, getCount functions
	static class Counter{
		private int count;
		
		public Counter(int num) {
			this.count = num;
		}
		
		// "synchronized" ensures only one thread enter this method at a time.
		public synchronized void increment() {
			count ++;
		}
		
		public synchronized void decrement() {
			count --;
		}
		
		public synchronized int getCount() {
			return count;
		}
	} // end class Counter
	
	
	// Counter_up class that runs on threads
	static class Counter_up implements Runnable{
		
		private Counter counter;
		private int num;
		
		public Counter_up(Counter counter, int num) {
			this.counter = counter;
			this.num = num;
		}
		
		@Override
		public void run(){
			
			for (int i=0; i<num; i++) { 
				synchronized (counter) {
					counter.increment();
					System.out.printf("Count Up: %d%n", counter.getCount()); // print out
				}	
			}
		} // end override run
	} // end Counter_up class
	
	
	// Counter_down class
	static class Counter_down implements Runnable{
		private Counter counter;
		private int num;
		
		public Counter_down(Counter counter, int num) {
			this.counter = counter;
			this.num = num;
		}
		
		@Override
		public void run() {
			
			for (int i=0; i<num; i++) {
				synchronized (counter) {
					counter.decrement();
					System.out.printf("Count Down: %d%n", counter.getCount()); // print out
				}
			}
		} // end Override run
	} // end Counter_down class
	

} // end Portfolio class


