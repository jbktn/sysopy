import socket
import threading
import queue

def send_server_messages(server_socket, message_queue):
    while True:
        message = message_queue.get()
        if message is None:
            break
        server_socket.send(message.encode('utf-8'))

def receive_server_messages(server_socket):
    while True:
        try:
            data = server_socket.recv(1024)
            if not data:
                break
            print(f"Received: {data.decode('utf-8')}")
        except Exception as e:
            print(f"Error: {e}")
            break

    server_socket.close()

def handle_server(server_socket):
    message_queue = queue.Queue()
    send_thread = threading.Thread(target=send_server_messages, args=(server_socket, message_queue))
    receive_thread = threading.Thread(target=receive_server_messages, args=(server_socket,))
    send_thread.start()
    receive_thread.start()

    while True:
        response = input("Message: ")
        message_queue.put(response)

def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('192.168.1.102', 12345))

    print("[*] Connected to 192.168.1.102:12345")

    server_handler = threading.Thread(target=handle_server, args=(client,))
    server_handler.start()

if __name__ == "__main__":
    main()