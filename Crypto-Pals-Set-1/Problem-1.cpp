#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <cctype>

#if 0
typedef std::vector<uint8_t> bin;
typedef std::string hex;
typedef int

template <typename T>
class Number
{
    Number(T)
};

class Base
{
public:
    Base() = delete;


private:
}
#endif

namespace kim
{
    namespace crypto
    {
        class Hexadecimal
        {
        public:
            /* --- Constructors --- */
            Hexadecimal(const std::string p_hex)
            {
                if (p_hex.length() % 2 == 1) {
                    throw std::invalid_argument("Hexadecimal value does not have an even number of digits");
                } else {
                    for (auto& e: p_hex) {
                        if (!(e.isdigit() || ))
                    }


                    m_hex = p_hex;
                }
            }

            Hexadecimal(std::vector<uint8_t> p_bin)
            {
                for (auto& e : p_bin) {
                    uint8_t firstFourBits{e >> 4};
                    uint8_t secondFourBits{e & 0b00001111};
                }
            }

            Hexadecimal(const Hexadecimal& p_hex)
            {

            }

            #if 0
            Hexadecimal(uint64_t p_int)
            {
                m_hex = (hex.substr(i, 2), nullptr, 16));
            }
            #endif
            /* --- Destructor --- */
            ~Hexadecimal() {}

            /* --- Getter and Setter --- */

            std::string get_hex() const
            {
                return m_hex;
            }

            void set_hex(const std::string& p_hex)
            {
                m_hex = p_hex;
            }

            /* --- Printer --- */
            friend std::ostream& operator<<(std::ostream& os, const Hexadecimal* p_hex)
            {
                std::cout << p_hex->m_hex;
            }

            Binary to_bin() const
            {
                Binary ret{};

                for (int i{}; i < m_hex.length(); i += 2) {
                    ret.push_back(std::stoi(m_hex.substr(i, 2), nullptr, 16));
                }

                return ret;
            }

            // uint64_t toInteger()

        private:
            std::string m_hex;
            void intToHexHelper()
        };

        class Binary {
        public:
            /* --- Constructor --- */
            Binary(const std::vector<uint8_t> pBin) : mBin(pBin) {}

            /* --- Destructor --- */
            ~Binary() {}

            /* --- Getter and Setter --- */
            Binary getBin() const {
                return mBin;
            }

            void setBin(const std::vector<uint8_t>& pBin)
            {
                mBin = pBin;
            }

            void pushBack(const std::vector<uint8_t>& pBin)
            {
                mBin.insert(mBin.end(), pBin.begin(), pBin.end());
            }

            #if 0
            /* --- Printer --- */
            friend std::ostream& operator<<(std::ostream& os, const Binary& pBin)
            {
                for (auto& e : Bin.get_Bin()) {
                    pBin.print(e);
                    std::cout << " ";
                }
            }
            #endif

        private:
            std::vector<uint8_t> mBin;
            void print(uint64_t ui) {
                if (ui / 2 == 0) {
                    std::cout << ui % 2;
                } else {
                    print(ui / 2);
                    std::cout << ui % 2;
                }
            }
        };

        class Integer {
        public:
            Integer(const uint64_t ui) : Int(ui) {}
            ~Integer() {}

        private:
            uint64_t Int;
        };

        template <typename T>
        class Number {
        public:
            Number()
            std::vector<uint8_t> htob(const std::string& hex)
            {
                assert(hex.length() % 2 == 0);

                std::vector<uint8_t> ret{};
                ret.reserve(hex.length());

                for (int i{}; i < hex.length(); i += 2) {
                    ret.push_back(std::stoi(hex.substr(i, 2), nullptr, 16));
                }

                return ret;
            }
        private:
            Hexadecimal Hex;
            Binary Bin;
            Integer Int;
        };

        std::vector<uint8_t> htob(const std::string& hex)
        {
            assert(hex.length() % 2 == 0);

            std::vector<uint8_t> ret{};
            ret.reserve(hex.length());

            for (int i{}; i < hex.length(); i += 2) {
                ret.push_back(std::stoi(hex.substr(i, 2), nullptr, 16));
            }

            return ret;
        }

        std::string bto64(const std::vector<uint8_t>& bytes)
        {
            std::string ret{};
            const uint8_t fill{3 - (bytes.size() % 3)};
            const uint8_t base64_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                            'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                            'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                                            'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
                                            'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                            'j', 'k', 'l', 'm', 'n', 'o', 'p',
                                            'q', 'r', 's', 't', 'u', 'v', 'w',
                                            'x', 'y', 'z', '0', '1', '2', '3',
                                            '4', '5', '6', '7', '8', '9', '+',
                                            '/'};

            for (int i{}; i < (bytes.size() / 3) * 3; i += 3) {
                ret += base64_table[bytes[i] >> 2];
                ret += base64_table[((bytes[i] & 0b00000011) << 4) + (bytes[i + 1] >> 4)];
                ret += base64_table[((bytes[i + 1] & 0b00001111) << 2) + (bytes[i + 2] >> 6)];
                ret += base64_table[bytes[i + 2] & 0b00111111];
            }

            for (int i{}; i < 3 - (bytes.size() % 3); i++) {
                ret += '=';
            }

            return ret;
        }
    }
}


int main()
{
    #if 0
    std::vector<uint8_t> tmp = kim::base::htob("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
    std::cout << kim::base::bto64(tmp);
    #endif

    std::cout << kim::crypto::bto64({77, 97});

    return 0;
}
