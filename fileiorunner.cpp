#include "fileiorunner.h"

FileIoRunner::FileIoRunner()
{

}

#include <iostream>
#include <memory>

#include "filereadwrite.h"
#include "configline.h"
#include "configlineparse.h"
#include "configlinewrite.h"

void FileIoRunner::execute() const {
    ConfigLine data;
    data.id = "handratty";
    data.val2 = "kana";
    data.meta_val1 = "gawa";
    data.val3 = "vegas";

    std::cout << "File IO..." <<  std::endl;
//    std::unique_ptr<ConfigLineParse> parse_ptr = std::make_unique<ConfigLineParse>();
    std::shared_ptr<ConfigLineParse> parse_ptr = std::make_shared<ConfigLineParse>();
    std::shared_ptr<ConfigLineWrite> write_ptr = std::make_shared<ConfigLineWrite>();
    std::string filename = FileReadWrite::runner_file_name();

    FileReadWrite file_read_write(parse_ptr, write_ptr, filename);

    std::cout << "truncating " << filename << "..." << std::endl;
    file_read_write.clear_file();

    std::cout << "appending to " << filename << "..." << std::endl;
    file_read_write.append(data);

    std::cout << "reading from " << filename << "..." << std::endl;
    file_read_write.read();

    std::cout << "printing..." << std::endl;
    file_read_write.print();
}
