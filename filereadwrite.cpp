#include "filereadwrite.h"
#include <iostream>

std::string FileReadWrite::mFileName = "test_file.dat";

FileReadWrite::FileReadWrite(std::shared_ptr<ConfigLineParse> p_ptr, std::shared_ptr<ConfigLineWrite> w_ptr)
    : FileReadWrite(p_ptr, w_ptr, "test_file.dat") { }

FileReadWrite::FileReadWrite(std::shared_ptr<ConfigLineParse> p_ptr, std::shared_ptr<ConfigLineWrite> w_ptr, const std::string &file_name)
    : mParse_ptr(p_ptr), mWrite_ptr(w_ptr)
{
    this->set_file_name(file_name);
}

FileReadWrite::~FileReadWrite() {

}

void FileReadWrite::set_file_name(const std::string &file_name) {
    mFileName = file_name;
}


bool static inline is_empty(const std::string &s) {
    bool empty_string = true;
    for (std::string::const_iterator iter = begin(s); empty_string && iter != end(s); ++iter) {
        if (!std::isspace(*iter))
            empty_string = false;
    }
    return empty_string;
}

void FileReadWrite::read() {
    mLines.clear();
    std::ifstream file(mFileName, std::ios_base::in);
//    if (file.fail()) {
//        std::cout << "fail" << std::endl;
//    }
//    file.open(FileReadWrite::file_name());
    if (file.is_open()) {
        std::string line;
        do {
            std::getline(file, line);
            if (!is_empty(line))
                mLines.push_back(line);
        } while(!file.eof());
        file.close();
    }
}

void FileReadWrite::append(const std::string &line) {
    std::ofstream out_file(mFileName, std::ios_base::app);

    out_file << line << std::endl;
}

void FileReadWrite::append(const ConfigLine &data) {
    std::string str;
    mWrite_ptr->convert_data(data, str);
    this->append(str);
}

void FileReadWrite::clear_file() {
    std::ofstream trnc(mFileName, std::ios_base::trunc);
    trnc.close();
}

std::string FileReadWrite::test_file_name() {
    return "test_file.dat";
}

std::string FileReadWrite::trash_file_name() {
    return "trash_file.dat";
}

std::string FileReadWrite::runner_file_name() {
    return "castellion_store.json";
}

void FileReadWrite::print() const {
    std::cout << mLines.size() << " line(s)" << std::endl;
    for_each(begin(mLines), end(mLines), [](const std::string &s) { std::cout << s << std::endl; });
}
