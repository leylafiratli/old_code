class Clock{
	public:
		Clock();	//contructor
		Clock(int hours, int minutes, int seconds);
		~Clock(); 	//destructor
		
		void setAlarm(int hours, int minutes, int seconds, bool alarmOn);
		void setClock(int hours, int minutes, int seconds);
		void alarmOff();
		void alarmOn();
		void addSecond();
		void displayTime();
		int getHours();
		int getMinnutes();
		int getSeconds();


	private:
		int _hours, _minutes, _seconds;
		int _ahours, _aminutes, _aseconds;
		bool _alarmOn;

}; //requires semicolon after bracket

//to compile: g++ -o testclock testclock.cpp clock.pp

//examples: Clock::Clock()
//int Clock::getSeconds()
