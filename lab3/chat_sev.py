import socket
import threading
import queue

def send_client_messages(client_socket, message_queue):
    while True:
        message = message_queue.get()
        if message is None:
            break
        client_socket.send(message.encode('utf-8'))

def receive_client_messages(client_socket):
    while True:
        try:
            data = client_socket.recv(1024)
            if not data:
                break
            print(f"Received: {data.decode('utf-8')}")
        except Exception as e:
            print(f"Error: {e}")
            break

    client_socket.close()

def handle_client(client_socket):
    message_queue = queue.Queue()
    send_thread = threading.Thread(target=send_client_messages, args=(client_socket, message_queue))
    receive_thread = threading.Thread(target=receive_client_messages, args=(client_socket,))
    send_thread.start()
    receive_thread.start()

    while True:
        response = input("Reply: ")
        message_queue.put(response)

def main():
    ip = '192.168.1.102'
    port = 12345

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((ip, port))
    server.listen(5)

    print(f"[*] Listening on {ip}:{port}")

    while True:
        client, addr = server.accept()
        print(f"[*] Accepted connection from: {addr[0]}:{addr[1]}")

        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

if __name__ == "__main__":
    main()