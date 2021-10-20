package com.yuanxi;

import javax.swing.*;
import java.awt.*;

public class Test {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Hello World");
        frame.setLayout(new FlowLayout());
        frame.setSize(800,600);
        frame.setLocationRelativeTo(null);


        frame.setVisible(true);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        JButton button = new JButton("按钮");
        button.setEnabled(true);
        button.setBorderPainted(false);
        button.setSize(100,50);
        frame.add(button);

        //JScrollPane scrollPane = new JScrollPane(button);
        //frame.add(scrollPane);
    }
}
