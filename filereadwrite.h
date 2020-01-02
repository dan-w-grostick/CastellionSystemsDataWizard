#ifndef FILEREADWRITE_H
#define FILEREADWRITE_H

#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include "configlineparse.h"
#include "configlinewrite.h"
#include "configline.h"

class FileReadWrite
{
public:
    FileReadWrite(std::shared_ptr<ConfigLineParse>, std::shared_ptr<ConfigLineWrite>);
    FileReadWrite(std::shared_ptr<ConfigLineParse>, std::shared_ptr<ConfigLineWrite>, const std::string&);
    ~FileReadWrite();
    void read();
    void append(const std::string&);
    void append(const ConfigLine&);
    static std::string test_file_name();
    static std::string trash_file_name();
    static std::string runner_file_name();
    void print() const;
    void clear_file();
protected:
    void set_file_name(const std::string&);
    static std::string mFileName;
    std::vector<std::string> mLines;
    std::shared_ptr<ConfigLineParse> mParse_ptr;
    std::shared_ptr<ConfigLineWrite> mWrite_ptr;
};

#endif // FILEREADWRITE_H
