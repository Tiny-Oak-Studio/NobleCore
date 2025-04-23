#include "Debug.h"

std::string Noble::Core::Debug::OpToString(const Op::Code op)
{
    std::stringstream ss;
    switch (op)
    {
        case Op::Code::Add:            ss << "ADD"; break;
        case Op::Code::Constant:       ss << "CST"; break;
        case Op::Code::ConstantString: ss << "STR"; break;
        case Op::Code::DefineGlobal:   ss << "DFG"; break;
        case Op::Code::Divide:         ss << "DIV"; break;
        case Op::Code::Equal:          ss << "EQL"; break;
        case Op::Code::False:          ss << "FAL"; break;
        case Op::Code::GetGlobal:      ss << "GEG"; break;
        case Op::Code::GetLocal:       ss << "GEL"; break;
        case Op::Code::Greater:        ss << "GTR"; break;
        case Op::Code::GreaterEqual:   ss << "GEQ"; break;
        case Op::Code::Jump:           ss << "JMP"; break;
        case Op::Code::JumpIfFalse:    ss << "JIF"; break;
        case Op::Code::JumpIfTrue:     ss << "JIT"; break;
        case Op::Code::Less:           ss << "LES"; break;
        case Op::Code::LessEqual:      ss << "LEQ"; break;
        case Op::Code::Loop:           ss << "LOP"; break;
        case Op::Code::Multiply:       ss << "MUL"; break;
        case Op::Code::Negate:         ss << "NEG"; break;
        case Op::Code::Not:            ss << "NOT"; break;
        case Op::Code::NotEqual:       ss << "NEQ"; break;
        case Op::Code::Null:           ss << "NUL"; break;
        case Op::Code::Pop:            ss << "POP"; break;
        case Op::Code::PopN:           ss << "PPN"; break;
        case Op::Code::Print:          ss << "PRT"; break;
        case Op::Code::Return:         ss << "RET"; break;
        case Op::Code::SetGlobal:      ss << "SEG"; break;
        case Op::Code::SetLocal:       ss << "SEL"; break;
        case Op::Code::Subtract:       ss << "SUB"; break;
        case Op::Code::True:           ss << "TRU"; break;
        default: ss << "Unknown operation '" << static_cast<unsigned>(op) << "'\n"; break;
    }
    return ss.str();
}