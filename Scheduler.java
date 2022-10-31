import java.util.Stack;
import java.time.LocalDateTime;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Scheduler {
    // Creating appropriate structures for holding appropriate tasks
    PriorityQueue<Task> priorityQueue;
    ArrayDeque<Task> queue;
    Stack<Task> stack;
    ArrayList<Task> completed;

    public Scheduler() {
        priorityQueue = new PriorityQueue<>();
        stack = new Stack<>();
        completed = new ArrayList<>();
        queue = new ArrayDeque<Task>();
    }

    public void createTask(int priority, String expression, String slave) {
        priorityQueue.add(new Task(priority, expression, slave));
    }

    public void createTask(String expression, String slave) {
        queue.offerLast(new Task(expression, slave));
    }

    public void runTask(int number) {
        for (Task task : priorityQueue) {
            if (number > 0) {
                task.setEvaluatedResult(task.evaluate());

                priorityQueue.remove(task);
                completed.add(task);

                number = number - 1;
            }
        }

        for (Task task : queue) {
            if (number > 0) {
                task.setEvaluatedResult(task.evaluate());

                queue.remove(task);
                completed.add(task);

                number = number - 1;

            }
        }

    }

    public void displayTasks() {
        for (Task task : priorityQueue) {
            task.toString();
        }

        for (Task task : queue) {
            task.toString();
        }

        for (Task task : completed) {
            task.toString();
        }
    }

    public void lowerPriority(LocalDateTime dateTime) {
        for (Task task : priorityQueue) {
            if (task.getDateTime().equals(dateTime)) {
                task.lowerPriority();
                if (task.getPriority() < 0) {
                    priorityQueue.remove(task);
                    queue.offerLast(task);
                }
            }
        }
    }

    public void raisePriority(String slave) {
        for (Task task : priorityQueue) {
            if (task.getSlave().equals(slave)) {
                task.raisePriority();
                if (task.getPriority() >= 0) {
                    queue.remove(task);
                    priorityQueue.add(task);
                }
            }
        }
    }

    public void cancelTask() {
        if (!priorityQueue.isEmpty()) {
            Task task = priorityQueue.peek();
            stack.add(task);
            System.out.println(
                    "Task: (" + task.getExpression() + ") has been cancelled having Priority: " + task.getPriority());
        } else {
            Task task = queue.pollLast();
            System.out.println(
                    "Task: (" + task.getExpression() + ") has been cancelled having Priority: " + task.getPriority());
            stack.add(task);
        }
    }

    public void unCancelTask() {
        if (!stack.isEmpty()) {
            Task task = stack.pop();

            if (task.getPriority() >= 0) {
                priorityQueue.add(task);
                System.out.println(
                        "Task (" + task.getExpression() + ") has been Un-Cancelled having Priority: "
                                + task.getPriority()
                                + " placed in Priority Queue.");

            } else {
                System.out.println(
                        "Task (" + task.getExpression() + ") has been Un-Cancelled having Priority: "
                                + task.getPriority()
                                + " placed in FIFO Queue.");
                queue.offerLast(task);
            }

        }
    }

}
