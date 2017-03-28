#include "process.hpp"

TPL::Process::Process(const string_type &command, const string_type &path,
                 std::function<void(const char* bytes, size_t n)> read_stdout,
                 std::function<void(const char* bytes, size_t n)> read_stderr,
                 bool open_stdin, size_t buffer_size):
                 closed(true), read_stdout(read_stdout), read_stderr(read_stderr), open_stdin(open_stdin), buffer_size(buffer_size) {
  open(command, path);
  async_read();
}

TPL::Process::~Process() {
  close_fds();
}

TPL::Process::id_type TPL::Process::get_id() {
  return data.id;
}

bool TPL::Process::write(const std::string &data) {
  return write(data.c_str(), data.size());
}
