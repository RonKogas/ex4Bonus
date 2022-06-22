#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>

const char* const DECK_FILE_NOT_FOUND_MESSAGE = "Deck File Error: File not found";
const char* const DECK_FILE_FORMAT_ERROR_MESSAGE = "Deck File Error: File format error in line ";
const char* const DECK_FILE_INVALID_SIZE_MESSAGE = "Deck File Error: Deck size is invalid";
const char* const INVALID_PUSH_TO_VECTOR_MESSAGE = "Invlid push of Card to Gang";


class InvalidPlayerName : public std::exception
{
public:
    InvalidPlayerName() = default;
    InvalidPlayerName(const InvalidPlayerName&) = default;
    ~InvalidPlayerName() = default;
    InvalidPlayerName& operator=(const InvalidPlayerName& other) = default;
};

class InvalidClass : public std::exception
{
public:
    InvalidClass() = default;
    InvalidClass(const InvalidClass&) = default;
    ~InvalidClass() = default;
    InvalidClass& operator=(const InvalidClass& other) = default;
};

class DeckFileNotFound : public std::exception
{
public:
    DeckFileNotFound() = default;
    DeckFileNotFound(const DeckFileNotFound&) = default;
    ~DeckFileNotFound() = default;
    DeckFileNotFound& operator=(const DeckFileNotFound& other) = default;
    const char* what() const noexcept override {
        return DECK_FILE_NOT_FOUND_MESSAGE;
    }
};

class DeckFileFormatError : public std::exception
{
public:
    DeckFileFormatError(int currentLine) :
    m_errorMessage(DECK_FILE_FORMAT_ERROR_MESSAGE + std::to_string(currentLine))
    {};
    DeckFileFormatError(const DeckFileFormatError&) = default;
    ~DeckFileFormatError() = default;
    DeckFileFormatError& operator=(const DeckFileFormatError& other) = default;
    const char* what() const noexcept override {
        return m_errorMessage.c_str();
    }

private:
    std::string m_errorMessage;
};

class DeckFileInvalidSize : public std::exception
{
public:
    DeckFileInvalidSize() = default;
    DeckFileInvalidSize(const DeckFileInvalidSize&) = default;
    ~DeckFileInvalidSize() = default;
    DeckFileInvalidSize& operator=(const DeckFileInvalidSize& other) = default;
    const char* what() const noexcept override {
        return DECK_FILE_INVALID_SIZE_MESSAGE;
    }
};

class InvalidPushToVector : public std::exception
{
public:
    InvalidPushToVector() = default;
    InvalidPushToVector(const InvalidPushToVector&) = default;
    ~InvalidPushToVector() = default;
    InvalidPushToVector& operator=(const InvalidPushToVector& other) = default;
    const char* what() const noexcept override {
        return INVALID_PUSH_TO_VECTOR_MESSAGE;
    }
};

#endif //EXCEPTION_H