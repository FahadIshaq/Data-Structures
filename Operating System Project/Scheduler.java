package Os;

import java.util.*;
import java.util.LinkedList;
import java.io.FileNotFoundException;
import java.io.File;

public class Scheduler { // This class is the main class of the project
    public static void Output(LinkedList<PCB> FinishedJobs, double Number, int WaitingTimee, int TurnaroundTimee) { // This
                                                                                                                    // method
                                                                                                                    // is
                                                                                                                    // used
                                                                                                                    // to
                                                                                                                    // output
                                                                                                                    // the
                                                                                                                    // results
                                                                                                                    // of
                                                                                                                    // the
                                                                                                                    // scheduling
                                                                                                                    // algorithms
        System.out.println(
                "ProcessName\tID\tBurst Time\tMemory\tArrival Time\tStart Time\tFinish Time\tWaiting Time\tTurnaround Time");
        String Output = "\nName\t\tID\t\tArrival\t\tBurst\t\tStart\t\tFinsh\t\tWaiting\t\tTurnaround";
        System.out.println(
                "-----------------------------------------------------------------------------------------------------------------"
                        + "-----------");

        for (PCB Job : FinishedJobs) { // This loop is used to output the results of the scheduling algorithms
            Output += "\n" + Job.Name + "		" + Job.ID + "		" + Job.ArrivalTime + "		" + Job.BurstTime
                    + "		"
                    + Job.StartTime + "		" + Job.FinishTime + "		" + Job.WaitingTime + "		"
                    + Job.TurnaroundTime;
        }
        Output += "\n\n\nTime			Total			Average";
        Output += "\n---------------------------------------------------------";
        Output += "\nTurnaround		" + TurnaroundTimee + "			" + String.format("%.2f", TurnaroundTimee / Number);

        Output += "\nWaiting			" + WaitingTimee + "			"
                + String.format("%.2f", WaitingTimee / Number);
        Output += "\n---------------------------------------------------------\n";

        System.out.println(Output + "\n");
    }

    public static void FirstComeFirstServe() { // This method is used to implement the First Come First Serve scheduling
                                               // algorithm

        LinkedList<PCB> JobQueue = new LinkedList<PCB>(); // This linked list is used to store the jobs that are waiting
                                                          // to be executed
        LinkedList<PCB> ReadyQueue = new LinkedList<PCB>(); // This linked list is used to store the jobs that are ready
                                                            // to be executed
        LinkedList<PCB> FinalJobs = new LinkedList<PCB>(); // This linked list is used to store the jobs that have been
                                                           // executed
        int TotalMemory = 8192; // This variable is used to store the total memory available
        int TotalTurnaroundTime = 0; // This variable is used to store the total turnaround time
        int TotalWaiting = 0; // This variable is used to store the total waiting time
        int CurrTime = 0; // This variable is used to store the current time
        try {
            JobQueue = GiveJobs(); // This method is used to get the jobs from the input file
        } catch (FileNotFoundException e) { // This catch block is used to catch the exception if the input file is not
                                            // found
            System.out.println(e.toString()); // This line is used to print the exception
        }
        System.out.print(
                "-------------------------------------------------------------FCFS----------------------------------------------------------\n");
        while (true) { // This loop is used to implement the First Come First Serve scheduling
                       // algorithm
            if (JobQueue.getFirst().MemoryRequired > TotalMemory || JobQueue.isEmpty())
                break;
            ReadyQueue.addLast(JobQueue.pop()); // This line is used to add the job to the ready queue
            ReadyQueue.getLast().State = "Ready";
            TotalMemory -= ReadyQueue.getLast().MemoryRequired; // This line is used to update the total memory
                                                                // available
        }
        // change while loo[ ]
        while (!ReadyQueue.isEmpty()) { // This loop is used to implement the First Come First Serve scheduling
                                        // algorithm

            PCB RunningJob = ReadyQueue.pop();
            RunningJob.StartTime = CurrTime; // This line is used to update the start time of the job
            RunningJob.State = "Running";
            RunningJob.FinishTime = RunningJob.StartTime + RunningJob.BurstTime; // This line is used to update the
                                                                                 // finish
                                                                                 // time of the job
            RunningJob.WaitingTime = RunningJob.StartTime - RunningJob.ArrivalTime;
            RunningJob.TurnaroundTime = RunningJob.BurstTime + RunningJob.WaitingTime; // This line is used to update
                                                                                       // the
                                                                                       // turnaround time of the job
            CurrTime = RunningJob.FinishTime;
            TotalWaiting += RunningJob.WaitingTime; // This line is used to update the total waiting time
            TotalTurnaroundTime += RunningJob.TurnaroundTime;
            TotalMemory += RunningJob.MemoryRequired; // This line is used to update the total memory available
            RunningJob.State = "Terminated";

            FinalJobs.addLast(RunningJob); // This line is used to add the job to the final jobs list

            while (!JobQueue.isEmpty() && JobQueue.getFirst().MemoryRequired <= TotalMemory) { // This loop is used to
                                                                                               // implement the First
                                                                                               // Come First Serve
                                                                                               // scheduling algorithm
                ReadyQueue.addLast(JobQueue.pop()); // This line is used to add the job to the ready queue
                ReadyQueue.getLast().State = "Ready"; // This line is used to update the state of the job
                ReadyQueue.getLast().ArrivalTime = CurrTime; // This line is used to update the arrival time of the job
                TotalMemory -= ReadyQueue.getLast().MemoryRequired; // This line is used to update the total memory
                                                                    // available
            }
        }

        Output(FinalJobs, FinalJobs.size(), TotalWaiting, TotalTurnaroundTime); // This line is used to output the
                                                                                // results
                                                                                // of the scheduling algorithm
    }

    public static void ShortestJobFirst() { // This method is used to implement the Shortest Job First scheduling
                                            // algorithm

        LinkedList<PCB> CompletedJobs = new LinkedList<PCB>(); // This linked list is used to store the jobs that have
                                                               // been executed
        LinkedList<PCB> JobQueue = new LinkedList<PCB>(); // This linked list is used to store the jobs that are waiting
                                                          // to be executed
        LinkedList<PCB> ReadyQueue = new LinkedList<PCB>(); // This linked list is used to store the jobs that are ready
                                                            // to be executed
        int TotalMemory = 8192; // This variable is used to store the total memory available
        int CurrentTime = 0; // This variable is used to store the current time
        int TotalWaitingTime = 0; // This variable is used to store the total waiting time
        int TotalTurnaround = 0; // This variable is used to store the total turnaround time

        try { // This try block is used to get the jobs from the input file
            JobQueue = GiveJobs(); // This method is used to get the jobs from the input file
        } catch (FileNotFoundException e) {
            System.out.println(e.toString()); // This line is used to print the exception
        }
        System.out.print(
                "-------------------------------------------------------------SJF-------------------------------------------------------------\n");
        while (true) {
            if (JobQueue.isEmpty() || JobQueue.getFirst().MemoryRequired > TotalMemory) // This if statement is used to
                                                                                        // check if the job queue is
                                                                                        // empty
                                                                                        // or the memory required by the
                                                                                        // first job is greater than the
                                                                                        // total memory available
                break;
            ReadyQueue.addLast(JobQueue.pop()); // This line is used to add the job to the ready queue
            ReadyQueue.getLast().State = "Ready"; // This line is used to update the state of the job
            TotalMemory -= ReadyQueue.getLast().MemoryRequired; // This line is used to update the total memory
                                                                // available
        }

        while (!ReadyQueue.isEmpty()) { // This loop is used to implement the Shortest Job First scheduling
                                        // algorithm

            int ShortestJobIndex = 0;
            for (int i = 0; i < ReadyQueue.size(); i++)
                if (ReadyQueue.get(i).BurstTime < ReadyQueue.get(ShortestJobIndex).BurstTime)
                    ShortestJobIndex = i;

            PCB RunningJob = ReadyQueue.remove(ShortestJobIndex);
            RunningJob.State = "Running";
            RunningJob.StartTime = CurrentTime;
            RunningJob.FinishTime = RunningJob.StartTime + RunningJob.BurstTime;
            RunningJob.WaitingTime = RunningJob.StartTime - RunningJob.ArrivalTime;
            RunningJob.TurnaroundTime = RunningJob.BurstTime + RunningJob.WaitingTime;
            CurrentTime = RunningJob.FinishTime;
            TotalWaitingTime += RunningJob.WaitingTime;
            TotalTurnaround += RunningJob.TurnaroundTime;

            TotalMemory += RunningJob.MemoryRequired;
            RunningJob.State = "Terminated";

            CompletedJobs.addLast(RunningJob);

            while (!JobQueue.isEmpty() && JobQueue.getFirst().MemoryRequired <= TotalMemory) { // This loop is used to
                                                                                               // implement the Shortest
                                                                                               // Job First scheduling
                                                                                               // algorithm
                ReadyQueue.addLast(JobQueue.pop());
                ReadyQueue.getLast().State = "Ready";
                ReadyQueue.getLast().ArrivalTime = CurrentTime;
                TotalMemory -= ReadyQueue.getLast().MemoryRequired;
            }
        }

        Output(CompletedJobs, CompletedJobs.size(), TotalWaitingTime, TotalTurnaround);
    }

    public static void RoundRobin(int Quantum) {

        LinkedList<PCB> JobQueue = new LinkedList<PCB>(); // This linked list is used to store the jobs that are waiting
                                                          // to be executed
        LinkedList<PCB> ReadyQueue = new LinkedList<PCB>(); // This linked list is used to store the jobs that are ready
                                                            // to be executed
        LinkedList<PCB> CompletedJobs = new LinkedList<PCB>(); // This linked list is used to store the jobs that have
                                                               // been executed
        int Memory = 8192; // This variable is used to store the total memory available
        int CurrentTime = 0; // This variable is used to store the current time
        int TotalWaitingTime = 0; // This variable is used to store the total waiting time
        int TotalTurnaroundTime = 0; // This variable is used to store the total turnaround time
        int TotalCompletionTime = 0; // This variable is used to store the total completion time

        try {
            JobQueue = GiveJobs();
        } catch (FileNotFoundException e) {
            System.out.println(e.toString());
            System.exit(0);
        }
        double N = JobQueue.size();
        System.out.print("-------------------------------------------------------------Round Robin" + Quantum
                + "-------------------------------------------------------------\n");
        boolean condition = true; // This variable is used to check if the job queue is empty or not
        while (condition) { // This loop is used to implement the Round Robin scheduling algorithm
            if (JobQueue.isEmpty() || JobQueue.getFirst().MemoryRequired > Memory)
                break;
            ReadyQueue.addLast(JobQueue.pop());
            ReadyQueue.getLast().State = "Ready";
            Memory -= ReadyQueue.getLast().MemoryRequired; // This line is used to update the total memory
                                                           // available
        }

        while (!ReadyQueue.isEmpty()) { // This loop is used to implement the Round Robin scheduling algorithm

            PCB RunningJob = ReadyQueue.pop();

            if (RunningJob.BurstTime > Quantum) {
                RunningJob.State = "Running";
                RunningJob.BurstTime -= Quantum; // This line is used to update the burst time of the job
                RunningJob.StartTime = CurrentTime; // This line is used to update the start time of the job
                RunningJob.FinishTime = RunningJob.StartTime + Quantum;
                RunningJob.WaitingTime = RunningJob.StartTime - RunningJob.LastFinishTime; // This line is used to
                                                                                           // update
                                                                                           // the waiting time of the
                                                                                           // job
                RunningJob.TurnaroundTime = Quantum + RunningJob.WaitingTime;
                RunningJob.LastFinishTime = RunningJob.FinishTime;
                CurrentTime = RunningJob.FinishTime;
                TotalWaitingTime += RunningJob.WaitingTime;
                TotalTurnaroundTime += RunningJob.TurnaroundTime; // This line is used to update the total turnaround
                                                                  // time
                PCB Slice = new PCB(RunningJob);
                Slice.BurstTime = Quantum;
                CompletedJobs.addLast(Slice);
                RunningJob.State = "Ready";
                ReadyQueue.addLast(RunningJob); // This line is used to add the job to the ready queue
            }

            else {
                RunningJob.State = "Running";
                RunningJob.StartTime = CurrentTime; // This line is used to update the start time of the job
                RunningJob.FinishTime = RunningJob.StartTime + RunningJob.BurstTime;
                RunningJob.WaitingTime = RunningJob.StartTime - RunningJob.LastFinishTime;
                RunningJob.TurnaroundTime = RunningJob.BurstTime + RunningJob.WaitingTime;
                RunningJob.LastFinishTime = RunningJob.FinishTime; // This line is used to update the last finish time
                                                                   // of
                                                                   // the job
                RunningJob.State = "Terminated";
                CurrentTime = RunningJob.FinishTime;
                TotalWaitingTime += RunningJob.WaitingTime; // This line is used to update the total waiting time
                TotalTurnaroundTime += RunningJob.TurnaroundTime;
                TotalCompletionTime += RunningJob.FinishTime;
                Memory += RunningJob.MemoryRequired;
                RunningJob.State = "Terminated";

                CompletedJobs.addLast(RunningJob); // This line is used to add the job to the completed jobs queue

                while (!JobQueue.isEmpty() && JobQueue.getFirst().MemoryRequired <= Memory) { // This loop is used to
                                                                                              // implement the Round
                                                                                              // Robin scheduling
                                                                                              // algorithm
                    PCB LateJob = JobQueue.pop(); // This line is used to remove the job from the job queue
                    LateJob.State = "Ready"; // This line is used to update the state of the job
                    LateJob.ArrivalTime = CurrentTime; // This line is used to update the arrival time of the job
                    LateJob.LastFinishTime = LateJob.ArrivalTime; // This line is used to update the last finish time of
                                                                  // the job
                    Memory -= LateJob.MemoryRequired;
                    ReadyQueue.addLast(LateJob); // This line is used to add the job to the ready queue
                }
            }
        }

        // print the CPU scheduling report
        Output(CompletedJobs, N, TotalWaitingTime, TotalTurnaroundTime); // This line is used to print the CPU
                                                                         // scheduling
                                                                         // report
    }

    public static LinkedList<PCB> GiveJobs() throws FileNotFoundException {
        Scanner txt = new Scanner(new File("E:\\Work\\Exam\\OS-project\\os_project\\src\\Os\\testdata2.txt"));
        LinkedList<PCB> WorkingQueue = new LinkedList<PCB>(); // This linked list is used to store the jobs that are
                                                              // waiting to be executed

        while (txt.hasNext()) {
            String ProcessName = txt.nextLine(); // This variable is used to store the name of the process
            String[] Remaining = txt.nextLine().split(", "); // This variable is used to store the remaining time of the
                                                             // process
            int ProcessID = Integer.parseInt(Remaining[0]);
            int BurstTime = Integer.parseInt(Remaining[1]); // This variable is used to store the burst time of the
                                                            // process
            int RequiredMemory = Integer.parseInt(Remaining[2]);

            WorkingQueue.addLast(new PCB(ProcessName, ProcessID, BurstTime, RequiredMemory)); // This line is used to
                                                                                              // add the job to the
                                                                                              // working queue
        }

        txt.close(); // This line is used to close the file
        return WorkingQueue; // This line is used to return the working queue
    }

}
