#include "server/request.hpp"
#include "tools/concat.hpp"

Request::Request()
{

}

Request::~Request()
{

}

size_t Request::ContentLength(std::string content)
{
    return (content.length());
}

char *Request::Build(std::vector<std::string> items)
{
    std::string buffer = "";
    char *array = nullptr;

    for(const std::string &item : items) {
        buffer += item + '\n';
    }

    array = new char[buffer.size() + 1];
    std::strcpy(array, buffer.c_str());
    
    return array;
}

template <typename T>
char *Request::Send(int client_socket, std::vector<std::string> headers, T const &data)
{
    char *buffer = Build(data);

    send(client_socket, buffer, strlen(buffer), 0);

    return (nullptr);
}

template <typename T>
void Request::GET(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 12\n",
        "GET request!"
    };

    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::POST(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 13\n",
        "POST request!"
    };

    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::PUT(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 12\n",
        "PUT request!"
    };

    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::PATCH(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 14\n",
        "PATCH request!"
    };
    
    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::OPTIONS(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 16\n",
        "OPTIONS request!"
    };
    
    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::DELETE(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 15\n",
        "DELETE request!"
    };
    
    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::TRACE(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 15\n",
        "TRACE request!"
    };
    
    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::UPDATE(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 15\n",
        "UPDATE request!"
    };

    const char *response = Send(
        client_socket,
        header,
        data
    );
}

template <typename T>
void Request::CONNECT(int client_socket, std::vector<std::string> header, T const &data)
{
    data = {
        "HTTP/1.1 200 OK",
        "Content-Type: text/plain",
        "Content-Length: 16\n",
        "CONNECT request!"
    };
    
    const char *response = Send(
        client_socket,
        header,
        data
    );
}
