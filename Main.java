import java.time.LocalDateTime;
import java.time.Month;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        /*
         * Task Management System {CSC301, Fall2022}
         * ----------------------------------------------------------------------
         * 1- Create a Task
         * 2- Run Tasks
         * 3- Raise Priority of all tasks assigned to a specific slave robot
         * 4- Lower Priority of any task created before a given date
         * 5- Display Tasks
         * 6- Bonus Mark Functions added here
         * 0- Quit
         * ----------------------------------------------------------------------
         * Your choice? __
         * 
         */

        boolean quit = false;
        Scheduler scheduler = new Scheduler();

        while (!quit) {
            System.out.println("""

                        Task Management System {CSC301, Fall2022}
                        ----------------------------------------------------------------------
                        1- Create a Task
                        2- Run Tasks
                        3- Raise Priority of all tasks assigned to a specific slave robot
                        4- Lower Priority of any task created before a given date
                        5- Display Tasks
                        6- Bonus Mark Functions added here
                        0- Quit
                        ----------------------------------------------------------------------
                    """);

            /* Initializing Utils */
            Scanner scan = new Scanner(System.in);
            System.out.print("Your choice? : ");
            int choice = scan.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("""
                            ------------------------------------------------------
                                Provide following details for the task
                                1 - Priority (provide -1 if task is w/o priority)
                                2 - Expression of the task
                                3 - Slave to which the task is assigned to
                                """);

                    System.out.print("Priority: ");
                    int priority = scan.nextInt();

                    System.out.print("Expression: ");
                    String expression = scan.next();

                    System.out.print("Slave: ");
                    String slave = scan.next();

                    if (priority == -1) {
                        scheduler.createTask(expression, slave);
                    } else {
                        scheduler.createTask(priority, expression, slave);
                    }
                    break;
                case 2:
                    System.out.println("""
                            How many tasks should be executed ?
                            """);

                    System.out.print("tasks: ");
                    int tasks = scan.nextInt();

                    scheduler.runTask(tasks);
                    break;
                case 3:
                    System.out.println("""
                            ------------------------------------------
                            Following info is required:
                            - Slave

                            """);
                    System.out.print("Slave: ");
                    slave = scan.next();

                    scheduler.raisePriority(slave);
                    break;
                case 4:
                    System.out.println("""

                            --------------------------------------------
                            Please provide the following info:
                            - Year
                            - Month
                            - Day of the month
                            - Hour
                            - Minute

                            """);

                    System.out.print("Year: ");
                    int year = scan.nextInt();

                    System.out.print("Month (1-12): ");
                    int month = scan.nextInt();

                    System.out.print("Day of the Month: ");
                    int day_of_month = scan.nextInt();

                    System.out.print("Hour of the day (1-24): ");
                    int hour = scan.nextInt();

                    System.out.print("Minute of the Hour: ");
                    int minute = scan.nextInt();

                    LocalDateTime dateTime = LocalDateTime.of(year, Month.of(month), day_of_month, hour, minute);
                    scheduler.lowerPriority(dateTime);
                    break;
                case 5:
                    System.out.println("------------------------------------------");
                    scheduler.displayTasks();
                    break;
                case 6:
                    boolean loop = true;
                    while (loop) {
                        System.out.println("""
                                -------------------------------------------
                                Specify:
                                1- Cancel
                                2- Un-Cancel
                                3- quit

                                """);

                        System.out.print("Choice: ");
                        choice = scan.nextInt();

                        switch (choice) {
                            case 1:
                                scheduler.cancelTask();
                                break;
                            case 2:
                                scheduler.unCancelTask();
                                break;
                            case 3:
                                loop = false;
                                break;
                            default:
                                System.out.println("Choice Invalid.");
                                break;
                        }
                    }

                    break;
                case 0:
                    quit = true;
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }

        }
    }
}