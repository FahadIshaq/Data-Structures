package Os;

public class main_two {
    public static void main(String[] args) {
        Scheduler object = new Scheduler();
        object.FirstComeFirstServe();
        object.RoundRobin(3);
        object.RoundRobin(5);
        object.ShortestJobFirst();

    }
}
