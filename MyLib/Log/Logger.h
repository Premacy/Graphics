#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>

	enum log_type{
		console_log,
		file_log
	};

	enum log_level{
		critical,
		error,
		warning,
		info,
	};

class Logger{
	public:

		static void set_log_file(std::string filepath);
		static void log(const char* log_message, log_level level = info, log_type type = console_log);

		friend std::ostream& operator <<(std::ostream &stream, const char* log_message);

		static log_level log_filter;

	private:

		static void log_console(const char* log_message, log_level level = info);
		static void file_log(const char* log_message, log_level level = info);

		static std::string create_log_msg(const char* log_message, log_level level = info);

		static std::string logFilepath;
		static std::fstream logFile;

		static std::vector<std::string> log_buff;
		static std::size_t buff_size;

		static log_level current_log_level;
	};

template <typename T> void debug(const T &msg)
{
	std::cout << msg << std::endl;
}

#endif
 