#include "qwen.h"
#include <iostream>
#include <chrono>

int main() {
    // Initialize the Qwen model and tokenizer
    qwen::Pipeline pipeline("qwen7b-ggml.bin", "qwen.tiktoken");

    // Configure the generation parameters
    qwen::GenerationConfig gen_config;
    gen_config.max_length = 300;  // Set the desired maximum length for the response

    // Define your prompt
    std::vector<std::string> conversation = {"give me python code that says hello"};
    std::string prompt = "give me python code that says hello";

    // Measure the execution time of pipeline.chat
    auto start_time = std::chrono::high_resolution_clock::now();
    std::string response = pipeline.chat(conversation, gen_config);
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate and print the execution time
    auto execution_time_chat = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Execution Time for pipeline.chat: " << execution_time_chat << " milliseconds" << std::endl;

    // Measure the execution time of pipeline.generate
    start_time = std::chrono::high_resolution_clock::now();
    std::string response2 = pipeline.generate(prompt, gen_config);
    end_time = std::chrono::high_resolution_clock::now();

    // Calculate and print the execution time
    auto execution_time_generate = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Execution Time for pipeline.generate: " << execution_time_generate << " milliseconds" << std::endl;

    // Print the generated responses
    std::cout << "Generated Response (chat): " << response << std::endl;
    std::cout << "Generated Response (generate): " << response2 << std::endl;

    return 0;
}
