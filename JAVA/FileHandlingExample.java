import java.io.*;

public class FileHandlingExample {
    public static void main(String[] args) {
        String fileName = "source.txt";
        String content = "This is the content written to source.txt using BufferedWriter and FileWriter.";

        // Writing to the file
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            writer.write(content);
            System.out.println("Content successfully written to " + fileName);
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }

        // Reading from the file
        System.out.println("\nReading content from " + fileName + ":");
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line); // This is the "source stream"
            }
        } catch (IOException e) {
            System.out.println("Error reading from file: " + e.getMessage());
        }
    }
} 