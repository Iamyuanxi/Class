package com.SaleManage;

import com.SaleManage.Entity.Salesman;

import javax.swing.*;
import java.awt.*;

public class AddSalesmanWindow extends JDialog {
    JPanel jPanel = new JPanel(new FlowLayout(FlowLayout.CENTER,10,20));

    JLabel nameLabel = new JLabel("姓名",JLabel.RIGHT);
    JTextField nameTxt = new JTextField();

    JLabel numLabel = new JLabel("代号",JLabel.RIGHT);
    JTextField numTxt = new JTextField();

    JLabel genderLabel = new JLabel("性别",JLabel.RIGHT);
    JTextField genderTxt = new JTextField();

    JLabel birthLabel = new JLabel("出生年月",JLabel.RIGHT);
    JTextField birthTxt = new JTextField();

    JLabel phoneLabel = new JLabel("电话号码",JLabel.RIGHT);
    JTextField phoneTxt = new JTextField();

    JLabel addressLabel = new JLabel("居住地址",JLabel.RIGHT);
    JTextField addressTxt = new JTextField();

    JLabel dateLabel = new JLabel("入职时间",JLabel.RIGHT);
    JTextField dateTxt = new JTextField();

    JButton addButton = new JButton("添加");

    AddSalesmanWindowHandler addSalesmanWindowHandler;

    public AddSalesmanWindow(SalesmanManageWindow salesmanManageWindow) {
        super(salesmanManageWindow,"添加销售员信息",true);
        addSalesmanWindowHandler = new AddSalesmanWindowHandler(this,salesmanManageWindow);

        nameLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(nameLabel);
        nameTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(nameTxt);

        numLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(numLabel);
        numTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(numTxt);

        genderLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(genderLabel);
        genderTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(genderTxt);

        birthLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(birthLabel);
        birthTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(birthTxt);

        phoneLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(phoneLabel);
        phoneTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(phoneTxt);

        addressLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(addressLabel);
        addressTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(addressTxt);

        dateLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(dateLabel);
        dateTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(dateTxt);

        addButton.addActionListener(addSalesmanWindowHandler);
        jPanel.add(addButton);

        Container contentPane = getContentPane();
        contentPane.add(jPanel);

        setSize(350,500);
        setLocationRelativeTo(null);
        //只销毁当前窗口
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }

    public Salesman buildSalesman() {
        var salesman = new Salesman();

        salesman.setName(nameTxt.getText());
        salesman.setNumber(numTxt.getText());
        salesman.setGender(genderTxt.getText());
        salesman.setBirthDate(birthTxt.getText());
        salesman.setPhone(phoneTxt.getText());
        salesman.setAddress(addressTxt.getText());
        salesman.setEmployedDate(dateTxt.getText());

        return salesman;
    }
}
