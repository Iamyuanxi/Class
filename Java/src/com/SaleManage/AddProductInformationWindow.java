package com.SaleManage;

import com.SaleManage.Entity.ProductInformation;

import javax.swing.*;
import java.awt.*;

public class AddProductInformationWindow extends JDialog {
    JPanel jPanel = new JPanel(new FlowLayout(FlowLayout.CENTER,10,20));

    JLabel nameLabel = new JLabel("名称",JLabel.RIGHT);
    JTextField nameTxt = new JTextField();

    JLabel codeLabel = new JLabel("编码",JLabel.RIGHT);
    JTextField codeTxt = new JTextField();

    JLabel numLabel = new JLabel("总数",JLabel.RIGHT);
    JTextField numTxt = new JTextField();

    JLabel priceLabel = new JLabel("进价",JLabel.RIGHT);
    JTextField priceTxt = new JTextField();

    JLabel producerLabel = new JLabel("厂商",JLabel.RIGHT);
    JTextField producerTxt = new JTextField();

    JLabel dateLabel = new JLabel("入库时间",JLabel.RIGHT);
    JTextField dateTxt = new JTextField();

    JButton addButton = new JButton("添加");

    AddProductInformationWindowHandler addProductInformationWindowHandler;

    public AddProductInformationWindow(ProductManageWindow productManageWindow) {
        super(productManageWindow,"添加商品信息",true);
        addProductInformationWindowHandler = new AddProductInformationWindowHandler(this,productManageWindow);

        nameLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(nameLabel);
        nameTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(nameTxt);

        codeLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(codeLabel);
        codeTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(codeTxt);

        numLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(numLabel);
        numTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(numTxt);

        priceLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(priceLabel);
        priceTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(priceTxt);

        producerLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(producerLabel);
        producerTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(producerTxt);

        dateLabel.setPreferredSize(new Dimension(80,30));
        jPanel.add(dateLabel);
        dateTxt.setPreferredSize(new Dimension(200,30));
        jPanel.add(dateTxt);

        addButton.addActionListener(addProductInformationWindowHandler);
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

    public ProductInformation buildProductInformation() {
        var productInformation = new ProductInformation();

        productInformation.setName(nameTxt.getText());
        productInformation.setCode(codeTxt.getText());
        productInformation.setTotalNumber(Integer.valueOf(numTxt.getText()));
        productInformation.setUnitPrice(Double.valueOf(priceTxt.getText()));
        productInformation.setProducer(producerTxt.getText());
        productInformation.setStockDate(dateTxt.getText());

        return productInformation;
    }
}
