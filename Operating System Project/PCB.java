package Os;

public class PCB {
	String Name;
	int ID;
	int BurstTime;
	int MemoryRequired;
	String State;
	int ArrivalTime;

	int StartTime = 0;
	int FinishTime = 0;
	int WaitingTime = 0;
	int TurnaroundTime = 0;

	int LastFinishTime = 0;

	public PCB(String Name, int ID, int BurstTime, int MemoryRequired) {
		this.Name = Name;
		this.ID = ID;
		this.BurstTime = BurstTime;
		this.MemoryRequired = MemoryRequired;
		this.State = "New";
		this.ArrivalTime = 0;
	}

	public PCB(PCB Job) {
		this.Name = Job.Name;
		this.ID = Job.ID;
		this.BurstTime = Job.BurstTime;
		this.MemoryRequired = Job.MemoryRequired;
		this.State = Job.State;
		this.ArrivalTime = Job.ArrivalTime;
		this.StartTime = Job.StartTime;
		this.FinishTime = Job.FinishTime;
		this.WaitingTime = Job.WaitingTime;
		this.TurnaroundTime = Job.TurnaroundTime;
	}

}
