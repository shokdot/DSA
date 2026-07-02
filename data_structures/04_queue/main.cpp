#include <iostream>
#include "LinearQueue.hpp"
#include "CircularQueue.hpp"

int main()
{
    {
        LinearQueue q;

        std::cout << "Enqueue: 10, 20, 30, 40, 50\n";
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);

        std::cout << "Queue: ";
        q.display();

        std::cout << "Size: " << q.size() << '\n';
        std::cout << "Front element (peek): " << q.peek() << '\n';

        std::cout << "\nDequeue 2 elements\n";
        q.dequeue();
        q.dequeue();

        std::cout << "Queue: ";
        q.display();

        std::cout << "Size: " << q.size() << '\n';
        std::cout << "Front element (peek): " << q.peek() << '\n';

        std::cout << "\nAdd 60, 70 (note: linear queue will NOT reuse space)\n";

        try
        {
            q.enqueue(60); // this will fail when rear reaches MAX_SIZE - 1
            q.enqueue(70);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << '\n';
        }

        std::cout << "Final queue: ";
        q.display();

        std::cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << '\n';
        std::cout << "Is full? " << (q.isFull() ? "Yes" : "No") << '\n';
    }

    {
        CircularQueue q;

        try
        {
            // Check empty at start
            std::cout << "Empty? " << q.isEmpty() << "\n";

            // Fill queue
            for (int i = 1; i <= 8; i++)
            {
                q.enqueue(i);
                std::cout << "Enqueued: " << i << "\n";
            }

            std::cout << "Full? " << q.isFull() << "\n";

            // Try overflow
            try
            {
                q.enqueue(99);
            }
            catch (const std::exception &e)
            {
                std::cout << "Overflow caught: " << e.what() << "\n";
            }

            // Remove some elements
            std::cout << "Dequeue: " << q.dequeue() << "\n";
            std::cout << "Dequeue: " << q.dequeue() << "\n";
            std::cout << "Dequeue: " << q.dequeue() << "\n";

            // Add again to test circular behavior
            q.enqueue(100);
            q.enqueue(200);
            q.enqueue(300);

            // Print all remaining elements
            while (!q.isEmpty())
            {
                std::cout << "Dequeue: " << q.dequeue() << "\n";
            }

            // Underflow test
            try
            {
                q.dequeue();
            }
            catch (const std::exception &e)
            {
                std::cout << "Underflow caught: " << e.what() << "\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Unexpected error: " << e.what() << "\n";
        }
    }
}
