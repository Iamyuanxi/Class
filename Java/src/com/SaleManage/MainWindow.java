package com.SaleManage;

import javax.swing.*;
import java.awt.*;

public class MainWindow extends JFrame {
    SpringLayout springLayout = new SpringLayout();
    JPanel centerPanel = new JPanel(springLayout);

    JButton salesmanBtn = new JButton("人员管理");
    JButton productBtn = new JButton("产品管理");
    JButton producerBtn = new JButton("进货商管理");
    JButton customerBtn = new JButton("顾客管理");

    MainWindowHandler mainWindowHandler;

    public MainWindow() {
        super("销售管理系统");

        mainWindowHandler = new MainWindowHandler(this);

        Container contentPane = getContentPane();

        JLabel nameLabel = new JLabel("销售管理系统-JAVA版", JLabel.CENTER);
        nameLabel.setFont(new Font("华文行楷",Font.PLAIN,80));
        nameLabel.setPreferredSize(new Dimension(0,400));

        Font centerFont = new Font("楷体",Font.PLAIN,25);
        salesmanBtn.setFont(centerFont);
        productBtn.setFont(centerFont);
        producerBtn.setFont(centerFont);
        customerBtn.setFont(centerFont);

        //增加事件
        salesmanBtn.addActionListener(mainWindowHandler);
        productBtn.addActionListener(mainWindowHandler);
        producerBtn.addActionListener(mainWindowHandler);
        customerBtn.addActionListener(mainWindowHandler);

        //把组件加入面板
        centerPanel.add(salesmanBtn);
        centerPanel.add(productBtn);
        centerPanel.add(producerBtn);
        centerPanel.add(customerBtn);
        //弹簧布局
        layoutCenter();

        contentPane.add(nameLabel,BorderLayout.NORTH);
        contentPane.add(centerPanel,BorderLayout.CENTER);

        setSize(1000,800);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    private void layoutCenter() {
        //布局productBtn
        springLayout.putConstraint(SpringLayout.EAST,productBtn,-50,SpringLayout.HORIZONTAL_CENTER,centerPanel);
        springLayout.putConstraint(SpringLayout.NORTH,productBtn,20,SpringLayout.NORTH,centerPanel);
        //salesmanBtn
        springLayout.putConstraint(SpringLayout.EAST,salesmanBtn,-100,SpringLayout.WEST,productBtn);
        springLayout.putConstraint(SpringLayout.NORTH,salesmanBtn,0,SpringLayout.NORTH,productBtn);
        //producerBtn
        springLayout.putConstraint(SpringLayout.WEST,producerBtn,100,SpringLayout.EAST,productBtn);
        springLayout.putConstraint(SpringLayout.NORTH,producerBtn,0,SpringLayout.NORTH,productBtn);
        //customer
        springLayout.putConstraint(SpringLayout.WEST,customerBtn,100,SpringLayout.EAST,producerBtn);
        springLayout.putConstraint(SpringLayout.NORTH,customerBtn,0,SpringLayout.NORTH,productBtn);
    }

    public static void main(String[] args) {
        new MainWindow();
    }
}
