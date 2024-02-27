#include "Logger.h"

std::string Logger::logFilepath = "default_log_file.txt";

	void Logger::log(const char* log_message, log_level level, log_type type)
	{
		if(type == console_log){
			Logger::log_console(log_message, level);
		}else{
			Logger::file_log(log_message, level);
		}
	}

	std::string Logger::create_log_msg(const char* log_message, log_level level)
	{
		auto now = std::chrono::system_clock::now();
	   std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	 	
	 	std::string curr_time(std::ctime(&end_time));
	 	curr_time = " Time: " + curr_time;

	 	std::string final_log_message;

	    switch(level)
	    {
	    	case info:
	    		final_log_message = std::string("[*]Info: ") + std::string(log_message) + curr_time;
	    		break;
	    	case warning:
	    		final_log_message = std::string("[*]Warning: ") + std::string(log_message) + curr_time;
	    		break;
	    	case error:
				final_log_message = std::string("[*]Error: ") + std::string(log_message) + curr_time;
	    		break;
	    	case critical:
				final_log_message = std::string("[*]Critical: ") + std::string(log_message) + curr_time;
	    		break;
	    	default:
	    		final_log_message = std::string("Empty message");
	    }
	    return final_log_message;
	}

	void Logger::log_console(const char* log_message, log_level level)
	{
		std::string msg = create_log_msg(log_message, level);
		std::cout << msg << std::endl;
	}

void Logger::file_log(const char* log_message, log_level level){
		
}

void Logger::set_log_file(std::string filepath){
		//Logger::logFilePath = filepath;
}

std::ostream& operator <<(std::ostream &stream, const char *log_message){
	std::string result_message = Logger::create_log_msg(log_message);

	stream << result_message;
	return stream;
}